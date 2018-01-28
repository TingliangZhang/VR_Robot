import fileinput
def main():
    with fileinput.input() as f:
        for line in f:
            print(f.filename(), f.lineno(), line, end='')
if __name__ == '__main__':
    main()
