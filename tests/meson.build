test('basic', executable(
        'basic',
        ['basic.c'],
        include_directories: inc_lst,
    ),
    #args : files(['../ant_weights.bin']),
    is_parallel: false, timeout: 0
)

test('antenna_enumeration', executable(
        'antenna_enumeration',
        ['antenna_enumeration.c', '../src/antenna_weights.c'],
        include_directories: inc_lst,
    ),
    #args : files(['../ant_weights.bin']),
    is_parallel: false, timeout: 0
)

test('antenna_weights', executable(
        'antenna_weights',
        ['antenna_weights.c', '../src/antenna_weights.c'],
        include_directories: inc_lst,
    ),
    #args : files(['../ant_weights.bin']),
    is_parallel: false, timeout: 0
)
