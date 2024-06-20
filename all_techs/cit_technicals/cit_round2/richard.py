import collections
import datetime

def seconds_diff(start, end):
    diff = start - end
    return diff.total_seconds()

def create_time(time):
    hour, minute, second = map(int, time.split(":"))
    return datetime.time(hour=hour, minute=minute, second=second)

def solve(filename):
    function_order = []
    # Key: Function, Value: [(Timestamp, time_taken, depth)]
    finished_functions = collections.defaultdict(collections.deque)

    # Stack keeps track of functions in order
    # (function, timestamp)
    stack = []
    last_timestamp = None
    with open(filename, 'r') as FILE:
        # Process 
        for line in FILE.readlines():
            line = line.strip()
            func, is_start, _, start_time = line.split(" ")
            
            is_start = True if is_start == "Started" else False
            # Timestamps are all Time objects
            timestamp = create_time(start_time)
            timestamp_delta = datetime.timedelta(hours=timestamp.hour, minutes=timestamp.minute, seconds=timestamp.second)
            # Determine if we need to add new func to stack or remove from stack
            if stack:
                # Check if func is finished
                prev_func, start = stack[-1]

                # Need to check for unknowns...
                # TODO: Keeping track of the last timestamp...
                start_delta = datetime.timedelta(hours=start.hour, minutes=start.minute, seconds=start.second)
                diff = timestamp_delta - start_delta
                if func != prev_func and last_timestamp and last_timestamp < timestamp_delta:
                    # Unknown exists
                    function_order.append("<Unknown>")
                    finished_functions["<Unknown>"].append((start, diff.seconds, len(stack)))

                if prev_func == func and not is_start:   
                    # In reality we'll have finished functions in reverse order.
                    stack.pop()
                    finished_functions[func].append((start, diff.seconds, len(stack)))
                else:
                    stack.append((func, timestamp))
            else:
                stack.append((func, timestamp))
            # print(stack, finished_functions)

            if is_start:
                function_order.append(func)

            last_timestamp = timestamp_delta

    output(function_order, finished_functions)



def output(function_order, finished_functions):
    with open('output.txt', 'w') as FILE:
        for func in function_order:
            if func != "<Unknown>":
                start, time_taken, depth = finished_functions[func].popleft()
            else:
                start, time_taken, depth = finished_functions[func].popleft()

            FILE.write(f"{4 * depth * ' '}{func} started at {start}, lasted for {time_taken} seconds\n")
            

solve('log.txt')