#!/bin/sh

OS="osx"
SOURCE_DIR="undef"

PARAMS=""
while (( "$#" )); do
  case "$1" in
    -o|--os)
      OS=$2
      shift 2
      ;;
    -s|--source-dir)
      SOURCE_DIR=$2
      shift 2
      ;;
    --) # end argument parsing
      shift
      break
      ;;
    -*|--*=) # unsupported flags
      echo "Error: Unsupported flag $1" >&2
      exit 1
      ;;
    *) # preserve positional arguments
      PARAMS="$PARAMS $1"
      shift
      ;;
  esac
done
# set positional arguments in their proper place
eval set -- "$PARAMS"

if [[ "$SOURCE_DIR" == "undef" ]];then
    echo "Please provide the source directory."
    exit 1
fi

BUILD_DIR=${SOURCE_DIR}/build/root
DEPS_DIR=${SOURCE_DIR}/deps

echo "Installing CRAVE libraries"

if [[ "$OS" == "osx" ]];then
    echo "Mac OS"
    if [[ ! -d "/usr/local/crave" ]];then
	echo "/usr/local/crave does not exist. Creating it..."
	# This will create both crave and crave/lib, which is needed below
	mkdir -p /usr/local/crave/lib
    fi
    
    echo "Include headers..."
    cp -rf ${BUILD_DIR}/include /usr/local/crave/include
    cp -rf ${DEPS_DIR}/boolector-2.2.0/include/* /usr/local/crave/include
    cp -rf ${DEPS_DIR}/minisat-git/include/* /usr/local/crave/include
    cp -rf ${DEPS_DIR}/lingeling-ayv-86bf266-140429/include/* /usr/local/crave/include
    
    echo "Share directory..."
    cp -rf ${BUILD_DIR}/share /usr/local/crave/share

    echo "Libraries directory..."
    cp -rf ${BUILD_DIR}/lib/* /usr/local/crave/lib
    
    echo "Dependent libraries (boolector and lingeling)..."
    cp -f ${DEPS_DIR}/boolector-2.2.0/lib/libboolector.dylib ${DEPS_DIR}/lingeling-ayv-86bf266-140429/lib/liblingeling.dylib /usr/local/crave/lib
    
    echo "minisat library"
    cp -f ${DEPS_DIR}/minisat-git/lib/libminisat.2.1.0.dylib /usr/local/crave/lib
    cp -f ${DEPS_DIR}/minisat-git/lib/libminisat.2.dylib /usr/local/crave/lib
    rm -f /usr/local/crave/lib/libminisat.dylib; ln -s /usr/local/crave/lib/libminisat.2.dylib /usr/local/crave/lib/libminisat.dylib
else
    echo "Assuming Linux OS"
    if [[ ! -d "/quadric/usr/local/crave" ]];then
	echo "/quadric/usr/local/crave does not exist. Creating it..."
	# This will create both crave and crave/lib, which is needed below
	mkdir -p /quadric/usr/local/crave/lib
    fi

    echo "Include headers..."
    cp -rf ${BUILD_DIR}/include /quadric/usr/local/crave/include
    cp -rf ${DEPS_DIR}/boolector-2.2.0/include/* /quadric//usr/local/crave/include
    cp -rf ${DEPS_DIR}/minisat-git/include/* /quadric//usr/local/crave/include
    cp -rf ${DEPS_DIR}/lingeling-ayv-86bf266-140429/include/* /quadric//usr/local/crave/include
    
    echo "Share directory..."
    cp -rf ${BUILD_DIR}/share /quadric/usr/local/crave/share
    
    echo "Libraries directory..."
    cp -rf ${BUILD_DIR}/lib/* /quadric/usr/local/crave/lib
    
    echo "Dependent libraries (boolector and lingeling)..."
    cp -f ${DEPS_DIR}/boolector-2.2.0/lib/libboolector.so ${DEPS_DIR}/lingeling-ayv-86bf266-140429/lib/liblingeling.so /quadric/usr/local/crave/lib
    
    echo "minisat library"
    cp -f ${DEPS_DIR}/minisat-git/lib/libminisat.so.2.1.0 /quadric/usr/local/crave/lib
    cp -f ${DEPS_DIR}/minisat-git/lib/libminisat.so.2 /quadric/usr/local/crave/lib
    rm -f /quadric/usr/local/crave/lib/libminisat.so; ln -s /quadric/usr/local/crave/lib/libminisat.so.2 /quadric/usr/local/crave/lib/libminisat.so
fi

echo "CRAVE libraries installed"
