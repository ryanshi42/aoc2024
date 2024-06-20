use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let input = stdin.lock().lines().next().unwrap().unwrap();
    let mut parts = input.split_whitespace();
    let m = parts.next().unwrap();
    let n: i32 = parts.next().unwrap().parse().unwrap();
    let mut arr: Vec<i32> = Vec::new();
    let mut new_arr: Vec<Vec<i32>> = Vec::new();

    if n == 1 {
        println!("{}", m);
        return;
    }

    for i in m.chars() {
        let iz = i.to_digit(10).unwrap() as i32;
        if new_arr.is_empty() {
            new_arr.push(vec![1, iz]);
        } else {
            if iz == new_arr.last().unwrap()[1] {
                new_arr.last_mut().unwrap()[0] += 1;
            } else {
                new_arr.push(vec![1, iz]);
            }
        }
    }

    for blah in new_arr.iter() {
        arr.push(blah[0]);
        arr.push(blah[1]);
    }

    for _ in 0..(n - 2) {
        new_arr = Vec::new();
        for i in arr.iter() {
            let iz = *i;
            if new_arr.is_empty() {
                new_arr.push(vec![1, iz]);
            } else {
                if iz == new_arr.last().unwrap()[1] {
                    new_arr.last_mut().unwrap()[0] += 1;
                } else {
                    new_arr.push(vec![1, iz]);
                }
            }
        }
        arr = Vec::new();
        for blah in new_arr.iter() {
            arr.push(blah[0]);
            arr.push(blah[1]);
        }
    }

    println!("{}", arr.iter().map(|s| s.to_string()).collect::<String>());
}