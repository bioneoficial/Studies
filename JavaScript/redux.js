const createStore = (reducer, initialState) => {
  let state = initialState;
  let listeners = [];

  return {
    getState: () => state,

    dispatch: (action) => {
      const newState = reducer(state, action);
      state = newState;

      listeners.forEach((listener) => listener());
    },
    subscribe: (listener) => {
      listeners = [...listeners, listener];
    },
  };
};

const reducer = (state, action) => {
  switch (action.type) {
    case "INCREMENT":
      return state + action.data;
    case "DECREMENT":
      return state - action.data;
    case "changeData":
      return action.data;
    default:
      return state;
  }
};

const initialStateNumber = 1;

const store = createStore(reducer, initialStateNumber);

console.log("State #1", store.getState());

store.subscribe(() => {
  console.log("State after change", store.getState());
});

store.dispatch({ type: "INCREMENT", data: 3 });
console.log("State #2", store.getState());
store.dispatch({ type: "DECREMENT", data: 1 });

console.log("State #3", store.getState());

store.dispatch({ type: "changeData", data: "Hello World!" });
console.log("State #4", store.getState());
