## Maproute

Maproute is a command that parses the output of `traceroute` to print the
geolocation data of a packet's route to a host.

Underneath the hood it delegates the heavy lifting to `traceroute` so all
of it's options are supported. The only requirement it places on it is that
the `-n` flag is used, and it is automatically provided for you.

### Requirements

* Sqlite3
* Compiler with C++14

### Install

```

git clone git@github.com:wilbertom/maproute.git
cd maproute

mkdir /var/lib/maproute

make; make command; make db
make install

```

This will install the `tracerouteparseip`, `whereisip` and `maproute` commands
to `/usr/local/bin`. It will copy `libmaproute.so` to `/usr/local/lib` and
some development headers to `/usr/local/include`. Also it will install
an IP database that we use to find an IP's location to `/var/lib/maproute`.

### Usage

The basic usage is:

```
maproute google.com

```

See the `traceroute` manual, all of it's options should be supported.

There is also a `whereisip` command that could be useful.

```
whereisip
96.120.24.201
96.120.24.201, United States, New Jersey, Mount Laurel, 39.94782, -74.91168,

```

This command reads from standard input as opposed from a command line
argument. That's a little weird but it's because we use with pipes to create
the `maproute` command.


### IP Database

This command uses `IP2Location` database. The accuracy of the output is
completely dependent on how good that database is. If anyone knows of a more
accurate way of doing this let me know.

You should update your database monthly from `http://lite.ip2location.com`, in
order to download an updated copy of the database you need to register for
a free account.

After doing that you can update the database by downloading the lite DB5 CSV
file and running the following commands.

```
cd </path/to/repository/data>
mv </path/to/IP2LOCATION-LITE-DB5.CSV> .
./create
mv ip.db /var/lib/maproute/ip-location.db

```

For copyright reasons we can't keep an updated copy of the database with the
repository.

### Attribution

This site or product includes IP2Location LITE data available from
[http://lite.ip2location.com](http://lite.ip2location.com).
