###############################################################################
# NAME:             meson.build
#
# AUTHOR:           Ethan D. Twardy <ethan.twardy@gmail.com>
#
# DESCRIPTION:      Build script for the volumetric-diff tool
#
# CREATED:          01/26/2022
#
# LAST EDITED:      02/12/2022
#
# Copyright 2022, Ethan D. Twardy
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
###

libarchive = dependency('libarchive')
libglib = dependency('glib-2.0')
libserdec = dependency('libserdec')

executable(
  'volumetric-diff',
  'main.c',
  include_directories: ['../libvolumetric', '..'],
  dependencies: [libglib, libserdec, libarchive],
  link_with: [libvolumetric],
  install: true,
)

###############################################################################
