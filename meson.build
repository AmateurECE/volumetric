###############################################################################
# NAME:             meson.build
#
# AUTHOR:           Ethan D. Twardy <ethan.twardy@gmail.com>
#
# DESCRIPTION:      Top-level build script for the project.
#
# CREATED:          01/22/2022
#
# LAST EDITED:      01/07/2023
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

project('volumetric', 'c', version: '0.4.0',
       default_options: ['c_std=c11', 'buildtype=debug'])

add_project_arguments('-frecord-gcc-switches', language: 'c')
add_project_arguments('-D_DEFAULT_SOURCE', language: 'c')

subdir('libvolumetric')
subdir('volumetric-checkout')
subdir('volumetric-commit')
subdir('volumetric-diff')

###############################################################################
