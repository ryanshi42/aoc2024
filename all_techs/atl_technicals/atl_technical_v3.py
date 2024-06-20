from collections import defaultdict

class PopularityTracker():
    def __init__(self):
        self.top_popular = 0
        self.popularities = defaultdict(lambda: set())
        self.cids = defaultdict(lambda: 0)
        pass

    def increasePopularity(self, cid):
        curr_popularity = self.cids[cid] 
        self.cids[cid] = curr_popularity + 1
        if curr_popularity > 0:
            self.popularities[curr_popularity].remove(cid)
        self.popularities[curr_popularity + 1].add(cid)
        self.top_popular = max(self.top_popular, curr_popularity + 1)

    def decreasePopularity(self, cid):
        curr_popularity = self.cids[cid] 
        self.cids[cid] = curr_popularity - 1
        self.popularities[curr_popularity].remove(cid)
        self.popularities[curr_popularity - 1].add(cid)
        if not self.popularities[curr_popularity]:
            self.top_popular -= 1

    def mostPopular(self):
        print(self.popularities[self.top_popular] if self.top_popular != 0 else {-1})

popularityTracker = PopularityTracker()
popularityTracker.increasePopularity(7)
popularityTracker.increasePopularity(7)
popularityTracker.increasePopularity(8)
popularityTracker.mostPopular()
popularityTracker.increasePopularity(8)
popularityTracker.increasePopularity(8)
popularityTracker.mostPopular()
popularityTracker.decreasePopularity(8)
popularityTracker.decreasePopularity(8)
popularityTracker.mostPopular()
popularityTracker.decreasePopularity(7)
popularityTracker.decreasePopularity(7)
popularityTracker.decreasePopularity(8)
popularityTracker.mostPopular() 