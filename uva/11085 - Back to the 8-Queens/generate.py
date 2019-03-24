from typing import NamedTuple, Any


class Position:
    def __init__(self, row, column):
        self.row = row
        self.column = column


def generate_configurations(configuration = None, depth = 0):
    if configuration is None:
        configuration = [Position(row=0, column=column) for column in range(8)]

    if depth == 8:
        if configuration_is_valid(configuration):
            yield configuration
    else:
        while configuration[depth].row < 8:
            yield from generate_configurations(configuration, depth + 1)
            configuration[depth].row += 1
        configuration[depth].row = 0


def configuration_is_valid(configuration):
    def check_rows():
        rows = [position.row for position in configuration]
        if len(rows) != len(set(rows)):
            return False
        return True

    def check_diagonals():
        for pivot_position in configuration:
            for other_position in configuration:
                if pivot_position.row == other_position.row:
                    continue
                if abs(pivot_position.row - other_position.row) == abs(pivot_position.column - other_position.column):
                    return False
        return True

    return check_rows() and check_diagonals()


def output(configuration):
    print('Configuration {{ ', end='')
    for position in configuration:
        print(f'{position.row}, ', end='')
    print('}},')


def main():
    for configuration in generate_configurations():
        output(configuration)


main()
