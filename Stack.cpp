//
// Stack, default constructor
//
// initialized array variable
template <typename T>
Stack <T>::Stack ()
	:
	topS(-1), data_s()
{

}

//
// Stack, copy constructor
// initialized just in the member variables
template <typename T>
Stack <T>::Stack (const Stack & stack)
	:
	topS(stack.topS),
	data_s(stack.data_s)
{

}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{

}

//
// push, resize just in case we exceed default max size, add to the top of the stack
//
template <typename T>
void Stack <T>::push (T element)
{
	//this->data_s.resize(size()+1);
	this->topS += 1;
	this->data_s.set(topS, element);
}

//
// pop
//
template <typename T>
T Stack <T>::pop (void)
{
	if(this->topS == -1)
	{
		throw empty_exception();
	}
	int index = this->topS;
	this->topS = this->topS -1;
	return this->data_s.get(index);
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
// check for self-assignment
	if(this->data_s == rhs.data_s)
	{
		return *this;
	}
	this->topS = rhs.topS;
	this->data_s = rhs.data_s;

	return *this;
}

//
// clear
//
// reset top of stack to make it seem it has been cleared.
template <typename T>
void Stack <T>::clear (void)
{
	this->topS = -1;
}
