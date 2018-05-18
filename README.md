# DCMTK - HealthLytix Mods

## Note

This repo is a fork from the official DCMTK repo. Please refer to the official repo for the 
official DCMTK code.

## Differences

This repo adds some additional functionality to `storescp` package by:

- Added `--sort-on-uid` option, which creates a random UUID string that is used for the folder where to store the images per association. This means that each association gets a unique folder/UUID.
- Added `--exec-on-sassoc` option, which is an event that executes the command provided right after an association begins. The command can pass the following arguments:
        - #u (UUID for association)
        - #a (Called AE Title)
        - #c (Caller's AE Title)
        - #r (Caller's IP Address) // note, not working??
- Added `--exec-on-series` option, which is an event that executes the command provided when a new series is detected in the association. Useful if more than one series are being transmitted per association. The command passes the following arguments:
        - #u (UUID for association)
        - #a (Called AE Title)
        - #c (Caller's AE Title)
        - #r (Caller's IP Address) // note, not working??
        - #s (SeriesInstanceUID for the detected Series)
        - #e (StudyInstanceUID for the Study that belongs to the detected Series)
- Added `--exec-on-eoassoc` option, which is an event that executes the command provided right after an association ends. The command can pass the following arguments:
        - #u (UUID for association)
        - #a (Called AE Title)
        - #c (Caller's AE Title)
        - #r (Caller's IP Address) // note, not working??

Main changes to the code were done here:

- dcmnet/apps/CMakeLists.txt
- dcmnet/apps/storescp.cc

#### Note on Building

We added the libuuid library to the CMakeLists.txt file in order to include the required library to generate UUIDs. We are using an alpine docker to build. 
Be mindful of this when compiling. You might get errors if libuuid and uuid/uuid.h are not found on /usr/lib or /usr/include respectively.

## Example

```bash
/usr/local/bin/storescp --aetitle $AETITLE \
                        --fork \
                        --output-directory "/dicoms" \
                        --sort-on-uid \
                        --filename-extension '.dcm' \
                        --exec-on-sassoc "echo Receving #u #a #c #r" \
                        --exec-on-series "echo New Series #u #a #c #r #s #e" \
                        --exec-on-eoassoc "echo Finished #u #a #c #r" \
                        $PORT_TO_LISTEN

# sending a 2 series in one association to this storescp instance should produce the following:

Receving #u #a #c #r
New Series #u #a #c #r #s #e
New Series #u #a #c #r #s #e
Finished #u #a #c #r

```

### Please Note: New Directory Structure

With the example from above, the files will be saved in the following format

```bash

-- dicoms/
        -- input/
                -- series-instance-uid/
                -- series-instance-uid/
                        - images.dcm
                        - images.dcm

```



## DCMTK Specific

This DICOM ToolKit (DCMTK) package consists of source code, documentation
and installation instructions for a set of software libraries and
applications implementing part of the DICOM/MEDICOM Standard.

DCMTK contains the following sub-packages, each in its own sub-directory:

    config   - configuration utilities for DCMTK
    dcmdata  - a data encoding/decoding library and utility apps
    dcmfg    - a library for working with functional groups
    dcmimage - adds support for color images to dcmimgle
    dcmimgle - an image processing library and utility apps
    dcmiod   - a library for working with information objects and modules
    dcmjpeg  - a compression/decompression library and utility apps
    dcmjpls  - a compression/decompression library and utility apps
    dcmnet   - a networking library and utility apps
    dcmpmap  - a library for working with parametric map objects
    dcmpstat - a presentation state library and utility apps
    dcmqrdb  - an image database server
    dcmrt    - a radiation therapy library and utility apps
    dcmseg   - a library for working with segmentation objects
    dcmsign  - a digital signature library and utility apps
    dcmsr    - a structured reporting library and utility apps
    dcmtls   - security extensions for the network library
    dcmtract - a library for working with tractography results
    dcmwlm   - a modality worklist database server
    oflog    - a logging library based on log4cplus
    ofstd    - a library of general purpose classes
