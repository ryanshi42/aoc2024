class File():
    def __init__(self, name, size):
        self.name = name
        self.size = size

    def get_size(self):
        return self.size

class Collection():
    def __init__(self, name, files):
        self.name = name
        self.files = files

    def get_size(self):
        return sum([file.get_size() for file in self.files])

# file1.txt (size: 100)
# file2.txt (size: 200) in
# collection "collection1"
# file3.txt (size: 200) in
# collection "collection1"
# file4.txt (size: 300) in
# collection "collection2"
# and "collection3"
# file5.txt (size: 10)

# collections.append(File("file5", 10))

all_files = []
all_files = [
    File("file1", 100),
    File("file2", 200),
    File("file3", 200),
    File("file4", 200),
    File("file5", 10)
]

collections = {}
# collections.append(File("file1", 100))
collections["collection1"] = Collection("collection1", [all_files[0], all_files[1]])
collections["collection2"] = Collection("collection2", [all_files[4]])
collections["collection3"] = Collection("collection3", [all_files[3]])
collections["collection4"] = Collection("collection4", [all_files[4]])
collections["collection5"] = Collection("collection5", [all_files[2]])
collections["collection4"].files.append(collections["collection5"])

print(sorted([(collection.get_size(), collection.name) for collection in collections.values()]))
print(sum([file.get_size() for file in all_files]))

input = """files:
file1.txt (size: 100)
file2.txt (size: 200) in collection "collection1"
file3.txt (size: 200) in collection "collection1"
file4.txt (size: 300) in collection "collection2" and "collection3"
file5.txt (size: 10)

collections:
"collection1" has no parent
"collection2" has parent "collection1"
"collection3" has no parent"""