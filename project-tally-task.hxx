// Copyright (c) Paul Preney 2019. All Rights Reserved.
// For use by students in the University of Windsor's 2019W COMP3400 course.

#ifndef project_tally_task_hxx_
#define project_tally_task_hxx_

//===========================================================================

#include <cstddef>

//===========================================================================

class tally_predicate
{
public:
  using size_type = std::size_t;

private:
  size_type n_;
  size_type true_;

public:
  tally_predicate() : n_(0), true_(0)
    //error "TODO: default-construct-initialize n_ and true_"
  {
  }

  tally_predicate(tally_predicate const& t) = default;
  tally_predicate(tally_predicate&& t) = default;
  tally_predicate& operator =(tally_predicate const& t) = default;
  tally_predicate& operator =(tally_predicate&& t) = default;

  tally_predicate& operator +=(tally_predicate const& rhs)
  {
    //error "TODO: Add n_ and true_ to corresponding members in rhs."
    //error "TODO: Add the proper return statement here."
	this->n_ += rhs.n_;
	this->true_ += rhs.true_;
	
	return *this;
	
    // HINT: This is an assignment operator. Assignment operators virtually
    //       always return an lvalue reference to "this" object.
  }
  
  tally_predicate operator +(tally_predicate const& rhs) const
  {
    //error "TODO: Copy-construct *this into a local variable called tmp."
    //error "TODO: Apply tmp to the += operator to add rhs to it."
    //error "TODO: Add the proper return statement here."
	tally_predicate tmp(*this);
	tmp.n_ += rhs.n_;
	tmp.true_ += rhs.true_;
	
	//std::swap(tmp, this const&);
	
	return tmp;
	
  }

  size_type const& count() const
  {
    //error "TODO: Return n_."
	return this->n_;
  }
  
  size_type const& true_count() const
  {
    //error "TODO: Return true_."
	return this->true_;
  }
  
  size_type false_count() const
  {
    //error "TODO: Return n_ - true_."
	return this->n_ - this->true_;
  }

  template <typename T>
  tally_predicate& operator ()(T const& t)
  {
    //error "TODO: Increment n_ with prefix ++."
	++this->n_;
    //error "TODO: if t is true, add 1 to true_."
	
	this->true_ += bool(t);
    // HINT 1: Ensure t is a bool with "bool(t)".
    // HINT 2: Any bool coverted to an int is either 1 or 0, thus, 
    //         consider using += bool(t) in your answer. :-)
    //error "TODO: Return 'this' object."
	return *this;
  }
};

//===========================================================================

#endif //#ifndef project_tally_task_hxx_
