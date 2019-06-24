 Installing CRAVE in the Quadric Environment
============================================

The CRAVE library in this repository includes support for the Quadric environment.
This library is needed to run the random testbenches used in the compute fabric environments.

 Compiling the Library
----------------------

This assumes that you have already set up your compute-fabric environment as indicated [here](https://github.com/quadric-io/compute-fabric/blob/devel/README.md).
Once your compute-fabric enviornment has been set up, follow the instructions below to install CRAVE:

1. Create a new directory and change into it.
2. Clone the CRAVE repo: `git clone git@github.com:quadric-io/crave.git`
3. `cd crave`
4. `git submodule update --init --recursive`
5. Set the following environment variables:
```
SYSTEMC_HOME=/usr/local/systemc
BOOST_ROOT=/usr/local/Cellar/boost@1.55/1.55.0_1
GLOG_ROOT=no/glog/necessary
CRAVE_SOLVERS=boolector
```
Note: you might need to install boost version 1.55 if you don't have it (`brew install boost@1.55` installs this version). Any other version currently does not work with CRAVE.
6. `make`
7. `make test` (You should see all tests passing)
8. Run `install-crave-libs.sh` to install the libraries in your local area.

