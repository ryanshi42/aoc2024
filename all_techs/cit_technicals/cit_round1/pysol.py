
from typing import List, TypedDict, Enum
from abc import ABC

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

# result = [row for row in data if row['category'] == 'apple']

class Query(ABC):
    def __init__(self, field, op, value):
        self.field = field
        self.op = op
        self.value = value

# from abc import ABC, abstract_method
# class BaseOperator(ABC):
#     def check_op(self, data_field, value):
#         pass

# category == apple
query = (a and b and c) or (d and e and f)

row, query

class Query():
    def compute(query):

class BaseQuery():
    

class OrQuery():
    def compute(query):
        for q in queries:
            if compute(q):
    pass

class AndQuery():
    pass

# How do you make this more extensible
class LessThanOperator():
    def __init__(self):
        pass

    def check_op(self, data_field, value):
        return data_field < value

op_to_operator = {}
op_to_operator['<'] = LessThanOperator()

def is_op_true(data_field, op, value):
    return op_to_operator[op].check_op(data_field, value)

def get_row_if_any_query(queries, data):
    res = []
    for row in data:
        for q in queries:
            if is_op_true(row[q.field], q.op, q.value):
                res.append(row)
        # any([is_op_true])
    return res

def get_row_if_all_query(queries, data):
    res = []
    for row in data:
        all_satisfied = True
        for q in queries:
            if not is_op_true(row[q.field], q.op, q.value):
                all_satisfied = False
                break
        if all_satisfied:
            res.append(row)
        # any([is_op_true])
    return res

queries = [
    Query('price', '<', 1),
    # Query('location', '==', 'aisle 2')
]

# result = get_row_if_any_query(queries, data)
result = get_row_if_all_query(queries, data)

print(result)