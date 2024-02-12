# Studio 16

1. Rohan Tatikonda (r.s.tatikonda@wustl.edu), Evan Tompkins (e.b.tompkins@wustl.edu), Grayson Martin (g.p.martin@wustl.edu)
2. To declare an interface, create a C++ class with only pure virtual public methods.
3. (a) Interface inheritance, (b) member variables are private
4. We performed two tests to make sure our TextFile performed as expected. We first read in a vector of chars 
we then wrote the vector of chars which was saved in a private member variable(contents) to the output stream.
Running int, our output stream displayed the expected vector of chars. We then added one test: the getName function.
We printed the getName function to output stream and the out was as expected!
5. We accomplished this by making an alias to the base class. We made a reference to the base class and set our 
TextFile equal to the reference. Then we performed all the neccacery tests on the reference and not the TextFile itself.
```
int main(int argc, char* argv[]) {
	string s = "hi";
	vector<char> example;
	for(int i = 0; i < 5; i++){
		example.push_back('h');
	}
	TextFile tFile(s);
	AbstractFile & a = tFile;
	a.write(example);
	a.read();
	cout << a.getName() << endl;
}
```
6. All tests worked!
