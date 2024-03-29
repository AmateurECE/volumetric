///////////////////////////////////////////////////////////////////////////////
// NAME:            archive.h
//
// AUTHOR:          Ethan D. Twardy <ethan.twardy@gmail.com>
//
// DESCRIPTION:     An interface to construct files on disk from archives.
//
// CREATED:         01/22/2022
//
// LAST EDITED:     01/26/2022
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

#ifndef VOLUMETRIC_ARCHIVE_H
#define VOLUMETRIC_ARCHIVE_H

typedef struct FileContents FileContents;

// Lazy, universal archive extraction routine. Works for all archive files
// supported by BSD's libarchive.
void archive_extract_to_disk_universal(const FileContents* file,
                                       const char* location);

#endif // VOLUMETRIC_ARCHIVE_H

///////////////////////////////////////////////////////////////////////////////
