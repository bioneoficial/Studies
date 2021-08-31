import React from "react";
import Header from "../../components/Header";
import SearchBar from "../../components/SearchBar";
import Button from "../../components/Button";

const Homepage = () => {
  return (
    <>
      <Header />
      <SearchBar />
      Home Page
      <Button text="CLique" />
    </>
  );
};

export default Homepage;
