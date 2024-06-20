
# Suppose we need to investigate the performance problem of a program.
# In particular, we are interested in how much time is spent in each function. Therefore, we instrument each function to print a timestamp when it enters, and print a timestamp when it exits.

# E.g., each function looks like the following:

# void F1()
# {
#     PRINT_LOG (“F1 Started”);
#       if count < 3:
#         count = count++
#         F1()  
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


from collections import defaultdict

output_file = """F1 Started at 19:00:01
F2 Started at 19:00:03
F2 Ended at 19:00:04
F3 Started at 19:00:04
F3 Ended at 19:00:04
F1 Ended at 19:00:05
F3 Started at 19:00:04
F3 Started at 19:00:04
F3 Ended at 19:00:07
F3 Ended at 19:00:12"""

# fn_map maps function_name to a stack to indicate which function is currently being called
fn_map = defaultdict(lambda: [])

# F1 Started at 19:00:01, Elapsed time = 4 sec
#        <Unknown>,   Elapsed time = 2 sec
#        F2 Started at 19:00:03, Elapsed time = 1 sec
#        F3 Started at 19:00:04, Elapsed time = 1 sec

class Function():
    def __init__(self, function_name, start_time, prefix):
        self.function_name = function_name
        self.start_time = start_time
        self.elapsed = 0
        self.children = []
        self.prefix = prefix

    def append_child(self, child):
        self.children.append(child)

    def print_fn(self):
        print(f"{'    ' * self.prefix}{self.function_name} Started at {self.start_time}, Elapsed time = {self.elapsed} sec")
        elapsed_inner = 0
        for child in self.children:
            elapsed_inner += child.elapsed

        if self.elapsed - elapsed_inner and self.children:
            print(f"    {'    ' * self.prefix}<Unknown>,    Elapsed time = {self.elapsed - elapsed_inner} sec")

        for child in self.children:
            child.print_fn()

def sub_timestamps(end_ts, start_ts):
    end_hr, end_min, end_sec = [int(x) for x in end_ts.split(":")]
    start_hr, start_min, start_sec = [int(x) for x in start_ts.split(":")]

    end_secs = end_hr * 3600 + end_min * 60 + end_sec 
    start_secs = start_hr * 3600 + start_min * 60 + start_sec 

    res = end_secs - start_secs
    return res if res >= 0 else res + 3600 * 24


# takes lines, and returns a list of files at that depth
def parse_lines(curr_file):
    # e.g. 
    # F1 Started at 19:00:01
    # F2 Started at 19:00:03
    # F2 Ended at 19:00:04
    # F3 Started at 19:00:04
    # F3 Ended at 19:00:05
    # F1 Ended at 19:00:05

    # F1 Started at 19:00:01
    # F2 Started at 19:00:03
    # F3 Started at 19:00:04
    # F3 Ended at 19:00:05
    # F2 Ended at 19:00:04
    # F1 Ended at 19:00:05
    if not curr_file:
        return None

    stack = []
    ans = []

    for line in curr_file:

        tfn_name, tstart_string, _, tcurr_timestamp = line.split(" ")

        is_start = True if tstart_string == "Started" else False
        if is_start:
            new_fn = Function(tfn_name, tcurr_timestamp, len(stack))
            stack.append(new_fn)
        else:
            popped_fn = stack.pop()
            popped_fn.elapsed = sub_timestamps(tcurr_timestamp, popped_fn.start_time)

            if stack:
                stack[-1].append_child(popped_fn)
            else:
                ans.append(popped_fn)

    return ans
        
root_fns = parse_lines(output_file.split("\n"))
for root_fn in root_fns:
    root_fn.print_fn() 





