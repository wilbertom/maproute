
makefile_version = '0.1.0.0'
build = ./build
include=../include
cflags = -Wall -std=c++14 -g -DIP_DATABASE_PATH=\"/var/lib/maproute/ip-location.db\" \
	-lsqlite3
src = ../src/*
name = maproute
libname = lib$(name).so

install_include = /usr/local/include/$(name)
install_so = /usr/local/lib/$(libname)

all:
	echo "Using mymakefile version $(makefile_version)"
	make shared

command:
	echo "Creating the executable"
	cd build; \
	$(CXX) $(cflags) -I $(include) -l$(name) -L . ../cli/tracerouteparseip.cpp -o tracerouteparseip; \
	$(CXX) $(cflags) -I $(include) -l$(name) -L . ../cli/whereisip.cpp -o whereisip; \
	cp ../cli/maproute ./

clean:
	rm $(build)/*

shared:
	cd $(build); \
	$(CXX) $(cflags) -I $(include) -shared -fPIC -o $(libname) $(src)

install:
	cd $(build); \
	cp -R $(include)/$(name) $(install_include); \
	cp $(libname) $(install_so)

uninstall:
	cd $(build); \
	rm -rf $(install_include); \
	rm $(install_so)
