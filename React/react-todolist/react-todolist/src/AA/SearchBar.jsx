import React from "react";
import "./bar.css";

const SearchBar = () => {
  return <input type="text" className="search" />;
};

export default SearchBar;


class Button extends Component {


  render() {
    console.log("State", this.state);
    return <button>{this.props.text}</button>;
  }
}

export default Button;