# Suppose we need to investigate the performance problem of a program.
# In particular, we are interested in how much time is spent in each function. Therefore, we instrument each function to print a timestamp when it enters, and print a timestamp when it exits.

# E.g., each function looks like the following:

# void F1()
# {
#     PRINT_LOG (“F1 Started”);
#     ….
#     PRINT_LOG(“F1 Ended”);
# }

# void F2()
# {
#     PRINT_LOG (“F2 Started”);
#     ….
#     PRINT_LOG(“F2 Ended”);
# }

# void F3()
# {
#     PRINT_LOG (“F3 Started”);
#     ….
#     PRINT_LOG(“F3 Ended”);
# }

# In the end, we see the following output (suppose the file name is Log.txt):
# F1 Started at 19:00:01
# F2 Started at 19:00:03
# F2 Ended at 19:00:04
# F3 Started at 19:00:04
# F3 Ended at 19:00:05
# F1 Ended at 19:00:05

# As the above output is not very intuitive, we’d like to create a script to parse Log.txt and generate an output file like the following:

# F1 Started at 19:00:01, Elapsed time = 4 sec
#        <Unknown>,   Elapsed time = 2 sec
#        F2 Started at 19:00:03, Elapsed time = 1 sec
#        F3 Started at 19:00:04, Elapsed time = 1 sec

# Note that we’d like to achieve the following:
#    For each method invocation, we’d like to print out the Elapsed Time
#    If the call is nested, e.g., F1 calls F2, we’d like to indent F2

# Please design an efficient algorithm to generate the desired output.
# Please also make sure the algorithm can handle more complex situations, e.g., F1 calls F2, and F2 calls F1, and etc.

import datetime

def parse_time(time_str):
    hrs, mins, secs = map(int, time_str.split(":"))
    # time_obj = datetime.time(hour=hrs, minute=mins, second=secs)
    return datetime.timedelta(hours=hrs, minutes=mins, seconds=secs)

def time_diff(end_time, start_time):
    """
        Returns an integer of the time difference
    """
    return int((end_time - start_time).total_seconds())

class Function():
    def __init__(self, fn_name, depth, start_time_str):
        self.children = []
        self.fn_name = fn_name
        self.depth = depth
        self.start_time_str = start_time_str
        self.elapsed = 0

    def append_child(self, child_fn):
        self.children.append(child_fn)

    def print_fn(self):
        """
            Example output:
            F1 Started at 19:00:01, Elapsed time = 4 sec
                   <Unknown>,   Elapsed time = 2 sec
                   F2 Started at 19:00:03, Elapsed time = 1 sec
                   F3 Started at 19:00:04, Elapsed time = 1 sec
        """
        # First print parent string
        print(f"{'    ' * self.depth}{self.fn_name} Started at {self.start_time_str}, Elapsed time = {self.elapsed} sec")
        
        # Then check if any missing time, only if there are children

        if self.children:
            missing_time = self.elapsed - sum([child.elapsed for child in self.children])

            if missing_time:
                print(f"{'    ' * (self.depth + 1)}<Unknown>,   Elapsed time = {missing_time} sec")

        # Recursively print the children
        for child in self.children:
            child.print_fn()

def parse_log(log_file):
    stack = []
    output = []

    # Could also do something like `with open("log.txt", "r") as log_file:`
    for line in log_file.split("\n"):
        # print(line)
        fn_name, fn_start, _, fn_time = tuple(line.split(" "))
        is_new = True if fn_start == "Started" else False
        if not is_new and not stack:
            raise Exception("Invalid log file argument")
        elif is_new:
            # Is a new function, add new function to the stack
            new_fn = Function(fn_name, len(stack), fn_time)
            stack.append(new_fn)
        else: 
            # Not a new function
            top_fn = stack[-1]

            # Calculate time elapsed by function
            end_time = parse_time(fn_time)
            start_time = parse_time(top_fn.start_time_str)
            top_fn.elapsed = time_diff(end_time, start_time)

            stack.pop()

            # If no parent function, directly append to output
            if not stack:
                output.append(top_fn)
            else:
                stack[-1].append_child(top_fn)

    return output

def test_log_file(log_file):
    output = parse_log(log_file)
    for fn in output:
        fn.print_fn()

def run_tests():

    print("====== Beginning Test 1 ======")
    print()
    # Test 1
    log_file = """F1 Started at 19:00:01
F2 Started at 19:00:03
F2 Ended at 19:00:04
F3 Started at 19:00:04
F3 Ended at 19:00:05
F1 Ended at 19:00:05"""

    test_log_file(log_file)

    print()
    print("====== Beginning Test 2 ======")
    print()
    # Test 2
    log_file = """F1 Started at 19:00:01
F2 Started at 19:00:01
F1 Started at 19:00:01
F2 Started at 19:00:01
F1 Started at 19:00:01
F2 Started at 19:00:01
F2 Ended at 19:00:05
F1 Ended at 19:00:05
F2 Ended at 19:00:05
F1 Ended at 19:00:05
F2 Ended at 19:00:05
F1 Ended at 19:00:05"""

    test_log_file(log_file)

run_tests()

