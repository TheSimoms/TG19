import math
import sys

from itertools import zip_longest


# NOT FINISHED


def main():
    # Read N
    sys.stdin.readline().strip()

    points = []

    # Add all the points
    for line in sys.stdin:
        stripped = line.strip().split(' ')

        points.append((int(stripped[0]), int(stripped[1])))

    print(minimum_bounding_rectangle(points))


def minimum_bounding_rectangle(points):
    pi_half = math.pi / 2

    number_of_points = len(points)
    number_of_edges = number_of_points - 1

    edges = zero_matrix(number_of_edges, 2)

    for i in range(number_of_edges):
        edges[i] = [
            points[i + 1][0] - points[i][0],
            points[i + 1][1] - points[i][1],
        ]

    print(number_of_edges)
    print(edges)

    edge_angles = [
        math.atan2(edges[i][1], edges[i][0]) for i in range(number_of_edges)
    ]

    for i in range(number_of_edges):
        edge_angles[i] = abs(edge_angles[i] % pi_half)

    edge_angles = list(set(edge_angles))

    min_bbox = (0, sys.maxsize, 0, 0, 0, 0, 0, 0)

    for i in range(number_of_edges):
        rotated = [
            [
                math.cos(edge_angles[i]),
                math.cos(edge_angles[i] - pi_half),
            ],
            [
                math.cos(edge_angles[i] + pi_half),
                math.cos(edge_angles[i]),
            ]
        ]

        rot_points = dot(rotated, transpose(points))

        # Find min/max x,y points
        min_x = min(rot_points[0])
        max_x = max(rot_points[0])
        min_y = min(rot_points[1])
        max_y = max(rot_points[1])

        width = max_x - min_x
        height = max_y - min_y
        area = width * height

        if area < min_bbox[1]:
            min_bbox = (edge_angles[i], area, width, height, min_x, max_x, min_y, max_y)

    angle = min_bbox[0]
    rotated = [
        [
            math.cos(angle),
            math.cos(angle - pi_half),
        ],
        [
            math.cos(angle + pi_half),
            math.cos(angle),
        ],
    ]

    min_x = min_bbox[4]
    max_x = min_bbox[5]
    min_y = min_bbox[6]
    max_y = min_bbox[7]

    center_x = (min_x + max_x)/2
    center_y = (min_y + max_y)/2

    center_point = dot( [ center_x, center_y ], rotated )
    corner_points = zero_matrix(4, 2)

    corner_points[0] = dot( [ max_x, min_y ], rotated )
    corner_points[1] = dot( [ min_x, min_y ], rotated )
    corner_points[2] = dot( [ min_x, max_y ], rotated )
    corner_points[3] = dot( [ max_x, max_y ], rotated )

    return angle, min_bbox[1], min_bbox[2], min_bbox[3], center_point, corner_points


def zero_matrix(columns, rows):
    return [[0] * rows for _ in range(columns)]


def dot(a, b, is_2d=True):
    if is_2d:
        return [
            _dot(a[0], b),
            _dot(a[1], b),
        ]

    return _dot(a, b)

def _dot(a, b):
    return sum([a[i][0] * b[i] for i in range(len(b))])


def transpose(a):
    return list(map(list, zip_longest(*a, fillvalue='-')))


if __name__ == '__main__':
    main()
