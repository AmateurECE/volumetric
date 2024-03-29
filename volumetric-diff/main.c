///////////////////////////////////////////////////////////////////////////////
// NAME:            main.c
//
// AUTHOR:          Ethan D. Twardy <ethan.twardy@gmail.com>
//
// DESCRIPTION:     Entrypoint for the utility.
//
// CREATED:         01/26/2022
//
// LAST EDITED:     06/22/2022
//
// Copyright 2022, Ethan D. Twardy
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
////

#include <argp.h>
#include <assert.h>
#include <stdbool.h>

#include <config.h>
#include <volumetric/configuration.h>
#include <volumetric/docker.h>
#include <volumetric/volume.h>

const char* argp_program_version = "volumetric-diff " CONFIG_VERSION;
const char* argp_program_bug_address = "<ethan.twardy@gmail.com>";
static char doc[] = "Check for modifications in live configuration";
static char args_doc[] = "VOLUME_NAME";
static const int NUMBER_OF_ARGS = 1;
static struct argp_option options[] = {
    {"config", 'c', "FILE", 0,
     "Read configuration file FILE instead of default "
     "(" CONFIG_CONFIGURATION_FILE ")",
     0},
    {0},
};

static const char* CONFIGURATION_FILE = CONFIG_CONFIGURATION_FILE;

struct arguments {
    const char* volume_name;
    const char* configuration_file;
};

static error_t parse_opt(int key, char* arg, struct argp_state* state) {
    struct arguments* arguments = state->input;
    switch (key) {
    case 'c':
        arguments->configuration_file = arg;
        break;
    case ARGP_KEY_ARG:
        if (state->arg_num >= NUMBER_OF_ARGS) {
            argp_usage(state);
        }

        arguments->volume_name = arg;
        break;
    case ARGP_KEY_END:
        if (state->arg_num < NUMBER_OF_ARGS) {
            argp_usage(state);
        }

        break;
    default:
        return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

static struct argp argp = {options, parse_opt, args_doc, doc, 0, 0, 0};
int main(int argc, char** argv) {
    struct arguments arguments = {0};
    arguments.configuration_file = CONFIGURATION_FILE;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);
    VolumetricConfiguration config = {0};
    int result =
        volumetric_configuration_load(arguments.configuration_file, &config);
    assert(0 == result);

    // Get the volume from the configuration
    Volume volume = {0};
    bool found = volumetric_configuration_find_volume_by_name(
        &config, arguments.volume_name, &volume);
    if (true != found) {
        fprintf(stderr, "No volume named \"%s\" in the configuration\n",
                arguments.volume_name);
        return ENOENT;
    }

    // Do diff using volume
    Docker* docker = docker_proxy_new();
    result = volume_diff(&volume, docker);

    volume_release(&volume);
    volumetric_configuration_release(&config);
    return result;
}

///////////////////////////////////////////////////////////////////////////////
