FROM gcc:latest

WORKDIR /usr/src
COPY . /usr/src/

# ------------------------------------
# Install MulticoreBSP
RUN tar xvfJ MulticoreBSP-for-C.tar.xz
WORKDIR /usr/src/MulticoreBSP-for-C
RUN make

# Test if MulticoreBSP has been installed successfully
RUN make tests
RUN rm machine.info

# Add MulticoreBSP to path
ENV BSPPATH=/usr/src/MulticoreBSP-for-C/tools
ENV PATH=${BSPPATH}:${PATH}

# # ------------------------------------
# # Install BSPedupack
# WORKDIR /usr/src
# RUN tar xvfz BSPedupack2.0.tar.gz
# WORKDIR /usr/src/BSPedupack2.0
# RUN make
#
# The BSPedupack only contains exemplary files and does not need to be added to the compiler


WORKDIR /usr/src/app

# Compile C program
CMD ["sh", "-c", "bspcc -o ${NAME} ${NAME}.c"]

# # Profile mode
# CMD ["sh", "-c", "bspcc --profile -o ${NAME} ${NAME}.c"]

# # Debug mode
# CMD ["sh", "-c", "bspcc --debug -o ${NAME} ${NAME}.c"]