
from enum import Enum
from abc import ABC, abstractmethod
from typing import TypedDict, List

class Operator(Enum):
    LESS = 1
    GREATER = 2
    EQUALS = 3
    CONTAINS = 4

class Row(TypedDict):
    name: str
    category: str
    price: float
    rating: int
    location: str

data: List[Row] = [
    {
        'name': 'some very delicious apple', 
        'category': 'apple',
        'price': 1.3,
        'rating': 4,
        'location': 'aisle 3'
    },
    {
        'name': 'some soon rotten apple', 
        'category': 'apple',
        'price': 0.2,
        'rating': 1,
        'location': 'aisle 3'
    },
    {
        'name': 'the best banana ever',
        'category': 'banana',
        'price': 1.6,
        'rating': 5,
        'location': 'aisle 4'
    },
    {
        'name': 'orange oranges',
        'category': 'orange',
        'price': 1.1,
        'rating': 5,
        'location': 'aisle 2'
    },
    {
        'name': 'almost moldy oranges',
        'category': 'orange',
        'price': 0.3,
        'rating': 1,
        'location': 'aisle 2'
    },
]


class Query():
    def hello(self):
        print('hello')

    @abstractmethod
    def evaluate(self, row: Row) -> bool:
        pass

class LeafQuery(Query):
    def __init__(self, key, val, operator):
        self.key = key
        self.val = val
        self.operator = operator

    def evaluate(self, row: Row) -> bool:
        if self.operator == Operator.EQUALS:
            return row[self.key] == self.val
        elif self.operator == Operator.LESS:
            return row[self.key] < self.val
        elif self.operator == Operator.GREATER:
            return row[self.key] > self.val

        return False
            

# Composite query that combines multiple queries with logical OR
class OrQuery(Query):
    def __init__(self):
        self.queries = []

    def add_query(self, query: Query):
        self.queries.append(query)

    def evaluate(self, row: Row) -> bool:
        return any(query.evaluate(row) for query in self.queries)
    

class AndQuery(Query):
    def __init__(self):
        self.queries = []

    def add_query(self, query: Query):
        self.queries.append(query)

    def evaluate(self, row: Row) -> bool:

        return all(query.evaluate(row) for query in self.queries)


# Example Query
lhs = AndQuery()
lhs.add_query(LeafQuery('category', 'apple', Operator.EQUALS))
lhs.add_query(LeafQuery('price', 1, Operator.LESS))

middle = OrQuery()
middle.add_query(lhs)
middle.add_query(LeafQuery('category', 'banana', Operator.EQUALS))


def solve(data, query):
    return [row for row in data if query.evaluate(row)]

print(solve(data, middle))