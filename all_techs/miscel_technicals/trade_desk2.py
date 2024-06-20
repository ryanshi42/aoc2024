import abc

class Solution:
    def main():
        signals = Signal.initialize_system()
        while true:
            for s in signals:
                s.displaySignal()

class Signal:
    @staticmethod
    def initialize_system(self, trackCount, trackSignals):
        # Magic, actually returns anything we want
        self.trackCount = trackCount
        
        # array: i => trackSignals[i]
        self.trackSignals = trackSignals

    def displaySignal(self):
        # TODO implement this: The signal magically prints out whatever you print to the console
        # print('Prints something out')
        
        # for i in range(self.trackCount):
        #     if not self.containsTrain(i):
        #         print(f"Track number {i} is available to go on")
        #         print("green")
        #         return
        
        for i in range(self.trackCount):
            if self.has_path_to_dest(i):
                print(f"Track number {i} is available to go on")
                print("green")
                return

        print("red")
        return 
        
    def has_path_to_dest(self, trackNum):
        if self.containsTrain(trackNum):
            return False
            
        # Is the next signal a destination
        next_signal = self.trackSignals[trackNum]
        if next_signal.trackCount == 0:
            return True

        for i in range(next_signal.trackCount):
            if next_signal.has_path_to_dest(i):
                return True
                
        return False

    @abc.abstractmethod
    def containsTrain(self, trackNumber):
        # API to the signal
        return
