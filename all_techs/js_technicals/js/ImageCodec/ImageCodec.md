# ImageCodec

An image is a string of pixels, which we will assume are characters. We want to encode our image, which converts each pixel to one of the following encoded forms:
```
Raw(Pixel),    // Raw pixel value
Repeat,        // Repeat of the most recent pixel
Recent(usize), // Repeat of ith most recent pixel (excl. first most since that's Repeat)
```

Assuming this is ur recent pixel array: [A, B, C, D] (most to least recent)
- Repeat => A
- Recent(0) => B
- Recent(1) => C
- Recent(2) => D

Note that things move to the front of recent array if they appear as Recent. Example encoding:
A -> Raw(A) [A]
B -> Raw(B) [B A]
C -> Raw(C) [C B A]
C -> Repeat [C B A]
A -> Recent(1) [A C B]
B -> Recent(1) [B A C]
C -> Recent(1) [C B A]

## Tasks
- **Part 1:** encode an image into either Raw or Repeat
- **Part 2:** encode an image into Raw, Repeat or Recent
- **Part 3:** given an encoded image (list of encoded pixels) and an index x, decode the value of the pixel at index x. You cannot iterate from the beginning of the image to x, you must backtrack from x.