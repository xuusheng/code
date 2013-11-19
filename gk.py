a={1000:['B', 'K', 'M'], 1024:['B', 'Ki', 'Mi']}

def gk(size, k=True):
    if size < 0:
        raise ValueError('must be positive')
    m = 1000 if k else 1024
    for i in a[m]:
        if size < m:
            return '{0:.1f} {1}'.format(size, i)
        size /= m

    raise ValueError('too large')

if __name__ == '__main__':
    print(gk(123))
    print(gk(1234,False))
    print(gk(12345))
    print(gk(123456,False))
    print(gk(1234567))
    print(gk(12345678,False))
    print(gk(123456789))
    print(gk(1234567890, False))
    print(gk(12345678901))
    print(gk(123456789012, False))
