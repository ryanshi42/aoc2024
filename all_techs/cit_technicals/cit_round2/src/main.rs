

// # Suppose we need to investigate the performance problem of a program.
// # In particular, we are interested in how much time is spent in each function. Therefore, we instrument each function to print a timestamp when it enters, and print a timestamp when it exits.

// # E.g., each function looks like the following:

// # void F1()
// # {
// #     PRINT_LOG (“F1 Started”);
// #       if count < 3:
// #         count = count++
// #         F1()  
// #     PRINT_LOG(“F1 Ended”);
// # }

// # void F2()
// # {
// #     PRINT_LOG (“F2 Started”);
// #     ….
// #     PRINT_LOG(“F2 Ended”);
// # }

// # void F3()
// # {
// #     PRINT_LOG (“F3 Started”);
// #     ….
// #     PRINT_LOG(“F3 Ended”);
// # }

// # In the end, we see the following output (suppose the file name is Log.txt):
// # F1 Started at 19:00:01
// # F2 Started at 19:00:03
// # F2 Ended at 19:00:04
// # F3 Started at 19:00:04
// # F3 Ended at 19:00:05
// # F1 Ended at 19:00:05

// # As the above output is not very intuitive, we’d like to create a script to parse Log.txt and generate an output file like the following:

// # F1 Started at 19:00:01, Elapsed time = 4 sec
// #        <Unknown>,   Elapsed time = 2 sec
// #        F2 Started at 19:00:03, Elapsed time = 1 sec
// #        F3 Started at 19:00:04, Elapsed time = 1 sec

// # Note that we’d like to achieve the following:
// #    For each method invocation, we’d like to print out the Elapsed Time
// #    If the call is nested, e.g., F1 calls F2, we’d like to indent F2

// # Please design an efficient algorithm to generate the desired output.
// # Please also make sure the algorithm can handle more complex situations, e.g., F1 calls F2, and F2 calls F1, and etc.

use std::collections::HashSet;
use std::collections::VecDeque;


fn print_fn(f: Function) {
    let prefix = vec![" "; f.depth * 4].join("");
    let child_prefix = vec![" "; f.depth * 4 + 4].join("");
    
    println!("{}{} Started at {}:0{}:0{}, Elapsed time = {} sec", prefix, f.name, f.time_start.0, f.time_start.1, f.time_start.2, f.time_elapsed.unwrap());
    
    if !f.children.is_empty() {
        let s = f.children.iter().map(|cf| cf.time_elapsed.unwrap_or(0)).sum::<usize>();
        if s < f.time_elapsed.unwrap() {
            println!("{}<Unknown>,    Elapsed time = {} sec", child_prefix, f.time_elapsed.unwrap() - s);
        }
        for mut child in f.children {
            print_fn(child);
        }
    }
}


#[derive(Debug, PartialEq, Eq, Copy, Clone, Hash, PartialOrd, Ord)]
struct Coord {
    row: u8,
    col: u8,
}

impl Coord {
    fn neighbours(&self) -> Vec<Coord> {
        vec![
            Coord { row: self.row - 1, col: self.col },
            Coord { row: self.row + 1, col: self.col },
            Coord { row: self.row, col: self.col - 1 },
            Coord { row: self.row, col: self.col + 1 },
        ]
    }
}

struct Grid {
    
}


#[derive(PartialEq, Eq, Clone, )]
struct FShape {
    cost: u8,
    points: HashSet<Coord>,
}


#[derive(Debug, Clone, Eq, PartialEq, Hash)]
struct TempGrid {
    rows: [[u8; 3]; 6],
}

impl std::fmt::Display for TempGrid {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        Ok(())
    }
}

#[derive(Debug, PartialEq, Eq, Copy, Clone, Hash, PartialOrd, Ord)]
enum State {
    Impossible,
    Possible,
    Solved
}

impl FShape {
    fn left(&self) -> Option<Self> {
        if self.points.iter().any(|p| p.col == 0) {
            return None;
        }
        Some(Self {
            cost: self.cost,
            points: self.points.iter().map(|p| Coord { row: p.row, col: p.col - 1 }).collect()
        })
    }

    fn right(&self) -> Option<Self> {
        if self.points.iter().any(|p| p.col == 2) {
            return None;
        }
        Some(Self {
            cost: self.cost,
            points: self.points.iter().map(|p| Coord { row: p.row, col: p.col + 1}).collect()
        })
    }

    fn up(&self) -> Option<Self> {
        if self.points.iter().any(|p| p.row == 0) {
            return None;
        }
        Some(Self {
            cost: self.cost,
            points: self.points.iter().map(|p| Coord { row: p.row - 1, col: p.col }).collect()
        })
    }

    fn down(&self) -> Option<Self> {
        if self.points.iter().any(|p| p.row == 5) {
            return None;
        }
        Some(Self {
            cost: self.cost,
            points: self.points.iter().map(|p| Coord { row: p.row + 1, col: p.col }).collect()
        })
    }

    fn enlarge(&self, factor: u8) -> Self {
        Self {
            cost: self.cost * factor,
            points: self.points.iter().flat_map(|p| {
                let mut new_points = vec![];
                let x = p.row * factor;
                let y = p.col * factor;
                for i in 0..factor {
                    for j in 0..factor {
                        new_points.push(Coord { row: x + i, col: y + j});
                    }
                }
                new_points
            }).collect()
        }
    }

    fn flip(&self) -> Self {
        Self {
            cost: self.cost,
            points: self.points.iter().map(|p| Coord { row: p.col, col: p.row }).collect()
        }
    }

    fn rotate(&self) -> Self {
        Self {
            cost: self.cost,
            points: self.points.iter().map(|p| {
                match p {
                    Coord { row: 0, col: 0 } => Coord { row: 0, col: 2 },
                    Coord { row: 0, col: 1 } => Coord { row: 1, col: 2 },
                    Coord { row: 0, col: 2 } => Coord { row: 2, col: 2 },
                    Coord { row: 1, col: 0 } => Coord { row: 0, col: 1 },
                    Coord { row: 1, col: 1 } => Coord { row: 1, col: 1 },
                    Coord { row: 1, col: 2 } => Coord { row: 2, col: 1 },
                    Coord { row: 2, col: 0 } => Coord { row: 0, col: 0 },
                    Coord { row: 2, col: 1 } => Coord { row: 1, col: 0 },
                    Coord { row: 2, col: 2 } => Coord { row: 2, col: 0 },
                    _ => panic!(),
                }
            }).collect()
        }
    }

}

impl Grid {
    fn is_solved(&self, tg: &TempGrid) -> State {
        let mut full = 0;
        for row in tg.rows {
            if row.iter().sum::<u8>() == 3 {
                full += 1;
            }
        }
        if full == 5 {
            for row in tg.rows {
                println!("{:?}", row);
            }
            return State::Solved;
        } else {
            return State::Possible
        }
    }
}


fn time_diff(time_end: (i32, i32, i32), time_start: (i32, i32, i32)) -> usize {
    // Assume that the time_end > time_end
    let mut res = 0;
    let (mut a, mut b, c) = time_end;
    let mut secs = c - time_start.2;
    if secs < 0 {
        secs += 60;
        b -= 1;
    }

    res += secs as usize;

    let mut mins = b - time_start.1;
    if mins < 0 {
        mins += 60;
        a -= 1;
    }

    res += 60 * mins as usize;

    let hrs = a - time_start.0;
    if hrs < 0 {
        panic!("yea nah mate");
    }

    res += 60 * 60 * hrs as usize;
    
    res
}

struct Function<'a> {
    name: &'a str,
    depth: usize,
    time_elapsed: Option<usize>,
    time_start: (i32, i32, i32),
    children: Vec<Function<'a>>,
}


fn main() {
//     println!("Hello, world!");

//     let input = "F1 Started at 19:00:01
// F2 Started at 19:00:03
// F2 Ended at 19:00:04
// F3 Started at 19:00:04
// F3 Ended at 19:00:05
// F1 Ended at 19:00:05";

//     let mut stack = vec![];

//     for line in input.lines() {
//         let mut line_iter = line.split(" ");

//         // Assume that the input is well-formed!
//         let function_name = line_iter.next().unwrap();
//         let status = line_iter.next().unwrap();
//         let time = line_iter.skip(1).next().unwrap();
//         let parsed_time: Vec<_> = time.split(":").map(|s| s.parse::<i32>().unwrap()).collect();


//         match status {
//             "Started" => {
//                 let new_fn = Function {
//                     name: function_name,
//                     depth: stack.len(),
//                     time_elapsed: None,
//                     time_start: (parsed_time[0], parsed_time[1], parsed_time[2]),
//                     children: Vec::new(),
//                 };
//                 stack.push(new_fn);
//             },
//             "Ended" => {
//                 if stack.is_empty() || stack.last().unwrap().name != function_name {
//                     panic!("wtf happened to the top");
//                 }
//                 let mut last_function = stack.pop().unwrap();
//                 let elapsed_time = time_diff((parsed_time[0], parsed_time[1], parsed_time[2]), last_function.time_start);
//                 last_function.time_elapsed = Some(elapsed_time);
//                 if stack.len() > 0 {
//                     let mut parent = stack.pop().unwrap();
//                     parent.children.push(last_function);
//                     stack.push(parent);
//                 } else {
//                     print_fn(last_function);
//                 }


//             },
//             _ => {
//                 panic!("at the disco!");
//             }
//         };
//     }

    let mut q: VecDeque<TempGrid> = VecDeque::new();


    let grid = Grid {};

    let mut fshapes = vec![];

    // Make 1 fshape
    let def_points = HashSet::from([
        Coord { row: 0, col: 0 },
        Coord { row: 0, col: 1 },
        Coord { row: 0, col: 2 },
        Coord { row: 1, col: 0 },
    ]);
    let def_fshape = FShape { cost: 1, points: def_points };

    // Add all rotations
    let def_fshape_1 = def_fshape.rotate();
    let def_fshape_2 = def_fshape_1.rotate();
    let def_fshape_3 = def_fshape_2.rotate();
    fshapes.push(def_fshape);
    fshapes.push(def_fshape_1);
    fshapes.push(def_fshape_2);
    fshapes.push(def_fshape_3);

        // println!("Len of fshapes: {}", fshapes.len());
    // Add all flips
    fshapes = fshapes.into_iter().flat_map(|f| [f.clone(), f.flip()]).collect();
    println!("Len of fshapes: {}", fshapes.len());

        // println!("Len of fshapes: {}", fshapes.len());
    // Add all translations right
    fshapes = fshapes.into_iter().flat_map(|f| {
        let mut curr = Some(f);
        let mut ret = vec![];
        while let Some(z) = curr {
            ret.push(z.clone());
            curr = z.right();
        }
        ret
    }).collect();

    println!("Len of fshapes: {}", fshapes.len());

    // Add all translations down
    fshapes = fshapes.into_iter().flat_map(|f| {
        let mut curr = Some(f);
        let mut ret = vec![];
        while let Some(z) = curr {
            ret.push(z.clone());
            curr = z.down();
        }
        ret
    }).collect();

    println!("Len of fshapes: {}", fshapes.len());

    let tg = TempGrid { rows: [[0; 3]; 6] };

    q.push_back(tg);

    let mut seen = HashSet::new();

    while let Some(tg) = q.pop_back() {

        if seen.contains(&tg) {
            continue;
        }

        seen.insert(tg.clone());

        // println!("{}", tg.start_idx);
        println!("{}", tg);

        let solve_state = grid.is_solved(&tg);

        if solve_state == State::Solved {
            println!("SOLVED YTB");
            println!("{}", tg);
            break;
        } else if solve_state == State::Impossible {
            continue;
        }

        let TempGrid { rows: tt } = tg;

        let mut new_rows = tt.clone();
        
        for fshape in fshapes
                .iter()
                .filter(|f| f
                        .points
                        .iter()
                        .all(|p| tt[p.row as usize][p.col as usize] == 0)) {


            for p in fshape.points.iter() {
                new_rows[p.row as usize][p.col as usize] += 1;
            }
            q.push_back(TempGrid { rows: new_rows });
        }
    }

}
