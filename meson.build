project('mergesort', 'c', default_options: ['c_std=c11'])

incl = include_directories('includes')

mergesort = library('mergesort', 'src/mergesort.c', include_directories : incl)

executable('main', 'main.c', link_with: mergesort, include_directories: incl)

checkdep = dependency('check')
test_mergesort = executable(
	'test_mergesort', 'test/test_mergesort.c',
	link_with: mergesort,
	include_directories: incl,
	dependencies: checkdep
	)
test('test mergesort', test_mergesort)

