import numpy as np

antenna_names = [
    '1a',
    '1b',
    '1c',
    '1d',
    '1e',
    '1f',
    '1g',
    '1h',
    '1j',
    '1k',
    '2a',
    '2b',
    '2c',
    '2d',
    '2e',
    '2f',
    '2g',
    '2h',
    '2j',
    '2k',
    '2l',
    '2m',
    '3c',
    '3d',
    '3e',
    '3f',
    '3g',
    '3h',
    '3j',
    '3l',
    '4e',
    '4f',
    '4g',
    '4h',
    '4j',
    '4k',
    '4l',
    '5b',
    '5c',
    '5e',
    '5g',
    '5h',
    '0a',
]

NANTS = len(antenna_names)
NCHAN = 1
NPOL = 2

weights = np.ones((NANTS, NCHAN, NPOL), complex)
for i in range(NANTS):
    weights[i, 0, 0] = i

with open('ant_weights.bin', 'wb') as fio:
    fio.write(NANTS.to_bytes(4, byteorder='little', signed=False))
    fio.write(NCHAN.to_bytes(4, byteorder='little', signed=False))
    fio.write(NPOL.to_bytes(4, byteorder='little', signed=False))
    fio.write(('\0'.join(antenna_names)+'\0').encode('ascii'))
    fio.write(weights.tobytes())

with open('ant_weights.bin', 'rb') as fio:
    print('NANTS:', int.from_bytes(fio.read(4), byteorder='little'))
    print('NCHAN:', int.from_bytes(fio.read(4), byteorder='little'))
    print('NPOL:', int.from_bytes(fio.read(4), byteorder='little'))
