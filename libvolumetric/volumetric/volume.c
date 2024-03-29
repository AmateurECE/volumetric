///////////////////////////////////////////////////////////////////////////////
// NAME:            volume.c
//
// AUTHOR:          Ethan D. Twardy <ethan.twardy@gmail.com>
//
// DESCRIPTION:     Logic for deserializing volume files.
//
// CREATED:         01/17/2022
//
// LAST EDITED:     02/14/2022
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

#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include <serdec/yaml.h>

#include <volumetric/hash.h>
#include <volumetric/volume.h>
#include <volumetric/volume/archive.h>

///////////////////////////////////////////////////////////////////////////////
// Volume-Generic
////

static int volume_visit_map(SerdecYamlDeserializer* yaml, void* user_data,
                            const char* key) {
    Volume* volume = (Volume*)user_data;
    if (!strcmp("archive", key)) {
        volume->type = VOLUME_TYPE_ARCHIVE;
        return archive_volume_deserialize_yaml(yaml, &volume->archive);
    } else {
        return -EINVAL;
    }
}

///////////////////////////////////////////////////////////////////////////////
// Public API
////

int volume_deserialize_yaml(SerdecYamlDeserializer* yaml, Volume* volume) {
    return serdec_yaml_deserialize_map(yaml, volume_visit_map, volume);
}

void volume_free(Volume* volume) {
    volume_release(volume);
    free(volume);
}

void volume_release(Volume* volume) {
    switch (volume->type) {
    case VOLUME_TYPE_ARCHIVE:
        archive_volume_release(&volume->archive);
        break;
    default:
        assert(false);
    }
}

int volume_checkout(Volume* volume, Docker* docker) {
    switch (volume->type) {
    case VOLUME_TYPE_ARCHIVE:
        return archive_volume_checkout(&volume->archive, docker);
    default:
        assert(false);
    }
}

// Check for differences between the volume source and live
int volume_diff(Volume* volume, Docker* docker) {
    switch (volume->type) {
    case VOLUME_TYPE_ARCHIVE:
        return archive_volume_diff(&volume->archive, docker);
    default:
        assert(false);
    }
}

// Check for differences between the volume source and live
int volume_commit(Volume* volume, Docker* docker, bool dry_run) {
    switch (volume->type) {
    case VOLUME_TYPE_ARCHIVE:
        return archive_volume_commit(&volume->archive, docker, dry_run);
    default:
        assert(false);
    }
}

///////////////////////////////////////////////////////////////////////////////
