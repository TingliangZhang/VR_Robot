import argparse
parser = argparse.ArgumentParser()
parser.add_argument('--length', default=10, type=int, help='长度')
parser.add_argument('--width', default=5, type=int, help='长度')
args = parser.parse_args()
area = args.length * args.width
print('面积=', area)
