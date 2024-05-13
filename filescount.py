import os
import pathlib
import tarfile
from typing import List



if __name__ == '__main__':
    tarfiles_location: pathlib.Path = pathlib.Path(__file__).parent.parent.joinpath('work_data').joinpath('REAL-DATA')
    tarfiles: List[pathlib.Path] = list(tarfiles_location.glob('*.tar.gz'))
    csv_info_file: pathlib.Path = tarfiles_location.joinpath('video-files-frames-count.csv')

    csv_file_str = '#, Video Name, #RGB FILES, #DEPTH FILES'

    for index, tar_file_path in enumerate(tarfiles):
        print(f'processing tar file {index + 1} / {len(tarfiles)}')
        tar_file: tarfile.TarFile = tarfile.TarFile.open(f'{tar_file_path}', mode='r')
        parent, _, _ = [tinfo for tinfo in tar_file.getmembers() if tinfo.isdir()]
        rgb_files = [tinfo for tinfo in tar_file.getmembers() if tinfo.isfile() and 'RGB' in tinfo.name ]
        depth_files = [tinfo for tinfo in tar_file.getmembers() if tinfo.isfile() and 'DEPTH' in tinfo.name ]

        info_str = f'{index + 1}, {parent.name}, {len(rgb_files)}, {len(depth_files)};'
        csv_file_str = f'{csv_file_str}\n{info_str}'
    
    csv_file = open(csv_info_file, 'w')
    csv_file.write(csv_file_str)
    csv_file.close()