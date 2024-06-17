#!/bin/bash
cd build
search_dir=/home/ramsri00/work_data/INPUT_VIDEOS/Khalil
FORMAT=$1
OUTPUT_DIR=/home/ramsri00/work_data/KhalilVideos/Inputs
MV_FINISHED_DIR=/home/ramsri00/work_data/INPUT_VIDEOS/FinishedKhalil
EXPECTED_FILES_COUNT=800

if [ ! -d "$MV_FINISHED_DIR" ]; then
    mkdir $MV_FINISHED_DIR
fi

for videopath in "$search_dir"/*
do
    filename="$(basename ${videopath%.*})"
    rgbdir=${filename}/RGB
    depthdir=${filename}/DEPTH
    command="./AzureConverter -vpath ${videopath} -format ${FORMAT} --depthdir ${depthdir} --rgbdir ${rgbdir}"
    echo $command
    tarcommand="tar -czf ./${filename}.tar.gz ./${filename}"
    mvcommand="mv -f ${filename} $OUTPUT_DIR/"
    $command
    numfiles=$(ls $rgbdir -l | grep -v ^d | wc -l)
    echo "$filename"
    echo "$rgbdir"
    echo "$depthdir"
    echo $numfiles
    if [ $numfiles -gt $EXPECTED_FILES_COUNT ]; then
        if [ -d "$OUTPUT_DIR/$filename" ]; then
            rm -rf $OUTPUT_DIR/$filename
        fi
        mv $videopath $MV_FINISHED_DIR/$filename.mkv
        $mvcommand
    fi
    # $tarcommand
    # $mvcommand    
    # exit
done


# ./AzureConverter -vpath ../captures/kev.mkv -format 2 --depthdir ./Kevin-RGB2D/DEPTH --rgbdir ./Kevin-RGB2D/RGB;
# ./AzureConverter -vpath ../captures/kev3.mkv -format 2 --depthdir ./Kevin3-RGB2D/DEPTH --rgbdir ./Kevin3-RGB2D/RGB;
# ./AzureConverter -vpath ../captures/baby_mannequin.mkv -format 2 --depthdir ./Baby-Mannequin-RGB2D/DEPTH --rgbdir ./Baby-Mannequin-RGB2D/RGB;
# ./AzureConverter -vpath ../captures/kid1_mannequin.mkv -format 2 --depthdir ./Kid1-Mannequin-RGB2D/DEPTH --rgbdir ./Kid1-Mannequin-RGB2D/RGB;
# ./AzureConverter -vpath ../captures/kid2_mannequin.mkv -format 2 --depthdir ./Kid2-Mannequin-RGB2D/DEPTH --rgbdir ./Kid2-Mannequin-RGB2D/RGB;
# ./AzureConverter -vpath ../captures/adolescent_mannequin.mkv -format 2 --depthdir ./Adolescent-Mannequin-RGB2D/DEPTH --rgbdir ./Adolescent-Mannequin-RGB2D/RGB; 
# ./AzureConverter -vpath ../captures/Kevin-10-49-57-12.mkv -format 2 --depthdir ./Kevin-10-49-57-12/DEPTH --rgbdir ./Kevin-10-49-57-12/RGB;
# ./AzureConverter -vpath ../captures/Kevin-10-53-56-80.mkv -format 2 --depthdir ./Kevin-10-53-56-80/DEPTH --rgbdir ./Kevin-10-53-56-80/RGB;
# ./AzureConverter -vpath ../captures/Kevin-10-49-57-12.mkv -format 2 --depthdir ./Kevin-10-49-57-12/DEPTH --rgbdir ./Kevin-10-49-57-12/RGB;
# ./AzureConverter -vpath ../captures/Kevin-10-49-57-12.mkv -format 2 --depthdir ./Kevin-10-49-57-12/DEPTH --rgbdir ./Kevin-10-49-57-12/RGB;