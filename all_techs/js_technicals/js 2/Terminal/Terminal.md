- you are first given a list of commands to initialise with
- the user will give some input, and you need to output all commands where the input is a substring
- output contains the list of commands (in the order they were originally given), an indication of how many commands are displayed out of the total, and the user input
```
hello
low
colo
—3/200—
> lo
```
- you are given a screen API which has operations to 1) clear the screen, 2) write one character (and move the writer forward to the right), 3) seek the writer to a certain position
- the screen has a fixed width, anything that goes past must be truncated or you get an error
- the screen has a fixed height, if there are more results that can fit only show the first <however many can fit>
- the user can move a cursor up/down the screen to select commands, looks like this:
```
hello
>> low
colo
—3/200—
> lo
```
- if the cursor goes 'off the screen' you need to move to the next "page" of results
