class BowlingScore():
    def __init__(self):
        self.curr_score = 0
        self.round = 0
        self.pins_left = 10
        self.curr_round_turns = 2
        self.multiplier = 1

    def knockdown(self, num_pins):
        self.pins_left -= num_pins
        self.curr_round_turns -= 1

        # reset the round
        if self.curr_round_turns == 0 or self.pins_left == 0:

            self.curr_score += self.multiplier * (10 - self.pins_left)

            if self.pins_left == 0:
                self.multiplier = 2
            else:
                self.multiplier = 1

            self.curr_round_turns = 2
            self.pins_left = 10
            self.round += 1


# given a list of scores like : 
hits = [1, 4, 5, 1, 10, 10, 10, 2, 2]
bs = BowlingScore()

for hit in hits:
    bs.knockdown(hit)

print(bs.curr_score)