class Collection():
    def __init__(self, name):
        self.name = name
        self.size = 0
        self.files = []
        self.parents = []

    def get_size(self):
        return self.size

    def add_file(self, file):
        self.files.append(file)
        self.size += file.size
        for parent in self.parents:
            parent.add_file(file)

    def add_parent(self, parent):
        self.parents.append(parent)

class File():
    def __init__(self, name, size):
        self.name = name
        self.size = size

    def get_size(self):
        return self.size


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

# multiple collections
# 

all_collections = {
    "Collection1" : Collection("Collection1"),
    "Collection2" : Collection("Collection2"),
    "Collection3" : Collection("Collection3"),
    "Collection4" : Collection("Collection4"),
    "Large Files" : Collection("Large Files")
}

all_files = {
    "File1" : File("File1", 100),
    "File2" : File("File2", 200),
    "File3" : File("File3", 200),
    "File4" : File("File4", 300),
    "File5" : File("File5", 10),
}

all_collections["Collection1"].add_parent(all_collections["Collection4"])
all_collections["Collection4"].add_parent(all_collections["Large Files"])


all_collections["Collection1"].add_file(all_files["File1"])
all_collections["Collection1"].add_file(all_files["File2"])
all_collections["Collection1"].add_file(all_files["File3"])
all_collections["Collection2"].add_file(all_files["File4"])
all_collections["Collection3"].add_file(all_files["File4"])

# print(all_files)
print("All file sizes =", sum([file.get_size() for file in all_files.values()]))
print("Sorted collection sizes =", sorted([(collection.get_size(), collection.name) for collection in all_collections.values()]))

# input = """files:
# file1.txt (size: 100)
# file2.txt (size: 200) in collection "collection1"
# file3.txt (size: 200) in collection "collection1"
# file4.txt (size: 300) in collection "collection2" and "collection3"
# file5.txt (size: 10)

# collections:
# "collection1" has no parent
# "collection2" has parent "collection1"
# "collection3" has no parent"""