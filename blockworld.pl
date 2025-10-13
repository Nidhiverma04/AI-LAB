% ------------------------------------
% BLOCK WORLD — FINAL FIXED VERSION
% ------------------------------------

% state(OnList, ClearList, Holding)
% OnList:  Facts like on(a,table)
% ClearList: Which blocks/tables are clear (e.g., [clear(b), clear(table)])
% Holding: What the agent is holding (or none)

% --- INITIAL AND GOAL STATES ---
initial(
    state(
        [on(a,table), on(b,table), on(c,a)],
        [clear(b), clear(c), clear(table)], % Added clear(table)
        none
    )
).

goal(
    state(
        [on(b,c), on(c,a), on(a,table)],
        [clear(b), clear(table)], % Added clear(table)
        none
    )
).

% --- MOVE RULES ---

% 1. Unstack X from Y (only if Y ≠ table) - FIXED
move(state(On, Clear, none),
     unstack(X, Y),
     state(NewOn, [clear(Y)|TempClear], X)) :- % TempClear is Clear without clear(X)
    member(on(X,Y), On),
    Y \= table,
    member(clear(X), Clear),
    % Effects: Remove on(X,Y), remove clear(X) (to TempClear), ADD clear(Y), hold X.
    delete(On, on(X,Y), NewOn),
    delete(Clear, clear(X), TempClear). % This removes clear(X)

% 2. Put block X down on table
move(state(On, Clear, X),
     putdown(X),
     state([on(X,table)|On], [clear(X)|Clear], none)) :-
    X \= none.

% 3. Pick up block X from table
move(state(On, Clear, none),
     pickup(X),
     state(NewOn, NewClear, X)) :-
    member(on(X,table), On),
    member(clear(X), Clear),
    delete(On, on(X,table), NewOn),
    delete(Clear, clear(X), NewClear).

% 4. Stack X on Y
move(state(On, Clear, X),
     stack(X, Y),
     state([on(X,Y)|On], [clear(X)|TempClear], none)) :- % TempClear is Clear without clear(Y)
    X \= none,
    member(clear(Y), Clear),
    % Effects: Add on(X,Y), remove clear(Y) (to TempClear), add clear(X), holds none.
    delete(Clear, clear(Y), TempClear). % This removes clear(Y)

% --- SEARCH (Depth-first) ---
dfs(State, Goal, _, []) :-
    State = Goal, !.

dfs(State, Goal, Visited, [Action|Rest]) :-
    move(State, Action, Next),
    \+ member(Next, Visited),
    dfs(Next, Goal, [Next|Visited], Rest).

% --- SOLVER ---
solve :-
    initial(I),
    goal(G),
    dfs(I, G, [I], Plan),
    write('--- Plan Found ---'), nl,
    forall(member(Action, Plan),
           (write('Perform action: '), write(Action), nl)),
    write('Goal achieved!'), nl.