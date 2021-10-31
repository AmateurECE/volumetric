///////////////////////////////////////////////////////////////////////////////
// NAME:            history.rs
//
// AUTHOR:          Ethan D. Twardy <ethan.twardy@gmail.com>
//
// DESCRIPTION:     Logic to encapsulate the History file.
//
// CREATED:         10/31/2021
//
// LAST EDITED:     10/31/2021
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

use std::io;

use crate::persistence::Persistent;
use crate::commit::Commit;

pub struct History {
    commits: Vec<Commit>,
}

impl History {}

impl Default for History {
    fn default() -> History {
        History { commits: Vec::new() }
    }
}

impl Persistent for History {
    fn load(target: &mut dyn io::Read) -> io::Result<History> {
        unimplemented!()
    }

    fn store(&self, target: &mut dyn io::Write) -> io::Result<()> {
        unimplemented!()
    }
}

///////////////////////////////////////////////////////////////////////////////