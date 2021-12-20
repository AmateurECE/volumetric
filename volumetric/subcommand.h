///////////////////////////////////////////////////////////////////////////////
// NAME:            subcommand.h
//
// AUTHOR:          Ethan D. Twardy <ethan.twardy@gmail.com>
//
// DESCRIPTION:     Declarations for subcommands
//
// CREATED:         12/19/2021
//
// LAST EDITED:     12/19/2021
//
// Copyright 2021, Ethan D. Twardy
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

#ifndef VOLUMETRIC_SUBCOMMAND_H
#define VOLUMETRIC_SUBCOMMAND_H

typedef struct VolumetricConfig VolumetricConfig;

int volumetric_add_packaged(VolumetricConfig* config, const char* url);

#endif // VOLUMETRIC_SUBCOMMAND_H

///////////////////////////////////////////////////////////////////////////////
