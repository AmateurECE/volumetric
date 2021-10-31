///////////////////////////////////////////////////////////////////////////////
// NAME:            main.rs
//
// AUTHOR:          Ethan D. Twardy <ethan.twardy@gmail.com>
//
// DESCRIPTION:     Entrypoint for the volumetric program.
//
// CREATED:         10/01/2021
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

use std::error::Error;
use std::io;

extern crate libvruntime;
extern crate libvremote;
use libvremote::remote;
use libvremote::remote::{FileRemote, ReadRemote, RemoteSpec, WriteRemote};
use libvremote::repository::RepositoryStructure;

mod arguments;
mod subcommands;

fn dispatch<P, R>(
    remote: R, matches: clap::ArgMatches, finder: RepositoryStructure
) -> Result<(), Box<dyn Error>>
where
    P: io::Read,
    R: ReadRemote<P>,
{
    let (subcommand, arg_matches) = matches.subcommand();
    match subcommand {
        // &"status" => subcommands::status(remote, arg_matches),
        // &"deploy" => subcommands::deploy(remote, arg_matches),
        value => Err(Box::new(libvruntime::error::VariantError::new(value))),
    }
}

fn dispatch_mut<P, R>(
    remote: R, matches: clap::ArgMatches, finder: RepositoryStructure
) -> Result<(), Box<dyn Error>>
where
    P: io::Read + io::Write,
    R: WriteRemote<P>
{
    let (subcommand, arg_matches) = matches.subcommand();
    match subcommand {
        "init" => subcommands::init::init(remote, arg_matches.expect(
            "subcommand init requires arguments. See the usage."), finder),
        // &"add" => subcommands::add(remote, arg_matches),
        // &"commit" => subcommands::commit(remote, arg_matches),
        // &"generate" => subcommands::generate(remote, arg_matches),
        // &"config" => subcommands::config(remote, arg_matches),
        // &"external" => subcommands::external(remote, arg_matches),
        _ => dispatch(remote, matches, finder),
    }
}

fn main() -> Result<(), Box<dyn Error>> {
    let matches = arguments::get_arguments();
    let uri = matches.value_of("uri").unwrap_or(".");
    let pathfinder = RepositoryStructure::default();
    match remote::remote_type(uri.to_string()).unwrap() {
        RemoteSpec::File(e) => dispatch_mut(
            FileRemote::new(e)?, matches, pathfinder),
    }?;

    Ok(())
}

///////////////////////////////////////////////////////////////////////////////
