template <class key_t, class val_t>
RBTMultimap<key_t, val_t>::RBTMultimap() : BSTMultimap<key_t, val_t>(){
	this->sentinel = new RBTNode<key_t, val_t> (key_t(), val_t(), 0);
	this->root = this->sentinel;
}

template <class key_t, class val_t>
RBTMultimap<key_t, val_t>::~RBTMultimap(){
	this->clear();
	delete this->sentinel;
}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::insert(const key_t& key, const val_t& value){
	RBTNode<key_t, val_t>* node = new RBTNode<key_t, val_t>(key, value, true);
	this->insertNode(node);
	this->insertFixup(node);
}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::rotateLeft(BSTNode<key_t, val_t>* node){
	if(node->getRightChild() == this->sentinel)
		return;
	RBTNode<key_t, val_t>* y = dynamic_cast<RBTNode<key_t, val_t>* >(node->getRightChild());
	node->setRightChild(y->getLeftChild());
	if(y->getLeftChild() != this->sentinel)
		y->getLeftChild()->setParent(node);
	y->setParent(node->getParent());
	if(node->getParent() == this->sentinel)
		this->root = y;
	else if(node == node->getParent()->getLeftChild())
		node->getParent()->setLeftChild(y);
	else
		node->getParent()->setRightChild(y);
	y->setLeftChild(node);
	node->setParent(y);
}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::rotateRight(BSTNode<key_t, val_t>* node){
	if(node->getLeftChild() == this->sentinel)
		return;
	RBTNode<key_t, val_t>* x = dynamic_cast<RBTNode<key_t, val_t>* >(node->getLeftChild());
	node->setLeftChild(x->getRightChild());
	if(x->getRightChild() != this->sentinel)
		x->getRightChild()->setParent(node);
	x->setParent(node->getParent());
	if(node->getParent() == this->sentinel)
		this->root = x;
	else if(node == node->getParent()->getLeftChild())
		node->getParent()->setLeftChild(x);
	else
		node->getParent()->setRightChild(x);
	x->setRightChild(node);
	node->setParent(x);
}


template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::insertFixup(RBTNode<key_t, val_t>* insertedNode){
	while(insertedNode->getParent()->isRed()){
		if(insertedNode->getParent() == insertedNode->getParent()->getParent()->getLeftChild()){
			RBTNode<key_t, val_t>* uncle = insertedNode->getParent()->getParent()->getRightChild();
			if(uncle->isRed()){
				insertedNode->getParent()->setIsRed(false);
				uncle->setIsRed(false);
				insertedNode->getParent()->getParent()->setIsRed(true);
				insertedNode = insertedNode->getParent()->getParent();
			}
			else{
				if(insertedNode == insertedNode->getParent()->getRightChild()){
					insertedNode = insertedNode->getParent();
					this->rotateLeft(insertedNode);
				}
				insertedNode->getParent()->setIsRed(false);
				insertedNode->getParent()->getParent()->setIsRed(true);
				this->rotateRight(insertedNode->getParent()->getParent());
			}
		}
		else{
			RBTNode<key_t, val_t>* uncle = insertedNode->getParent()->getParent()->getLeftChild();
			if(uncle->isRed()){
				insertedNode->getParent()->setIsRed(false);
				uncle->setIsRed(false);
				insertedNode->getParent()->getParent()->setIsRed(true);
				insertedNode = insertedNode->getParent()->getParent();
			}
			else{
				if(insertedNode == insertedNode->getParent()->getLeftChild()){
					insertedNode = insertedNode->getParent();
					this->rotateRight(insertedNode);
				}
				insertedNode->getParent()->setIsRed(false);
				insertedNode->getParent()->getParent()->setIsRed(true);
				this->rotateLeft(insertedNode->getParent()->getParent());
			}
		}
	}
	dynamic_cast<RBTNode<key_t, val_t>*>(this->root)->setIsRed(false);
	
}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::deleteFixup(RBTNode<key_t, val_t>* replacementNode){
	RBTNode<key_t, val_t>* node = replacementNode;
	while(node != this->root && !node->isRed()){
		if(node == node->getParent()->getLeftChild()){
			RBTNode<key_t, val_t>* sib = node->getParent()->getRightChild();
			if(sib->isRed()){
				sib->setIsRed(false);
				node->getParent()->setIsRed(true);
				rotateLeft(node->getParent());
				sib = node->getParent()->getRightChild();
			}
			if(!sib->getLeftChild()->isRed() && !sib->getRightChild()->isRed()){
				sib->setIsRed(true);
				node = node->getParent();
			}
			else{
				if(!sib->getRightChild()->isRed()){
					sib->getLeftChild()->setIsRed(false);
					sib->setIsRed(true);
					rotateRight(sib);
					sib = node->getParent()->getRightChild();
				}
				sib->setIsRed(node->getParent()->isRed());
				node->getParent()->setIsRed(false);
				sib->getRightChild()->setIsRed(false);
				rotateLeft(node->getParent());
				node = dynamic_cast<RBTNode<key_t, val_t>* >(this->root);
			}
		}
		else{
			RBTNode<key_t, val_t>* sib = node->getParent()->getLeftChild();
			if(sib->isRed()){
				sib->setIsRed(false);
				node->getParent()->setIsRed(true);
				rotateRight(node->getParent());
				sib = node->getParent()->getLeftChild();
			}
			if(!(sib->getRightChild()->isRed()) && !(sib->getLeftChild()->isRed())){
				sib->setIsRed(true);
				node = node->getParent();
			}
			else{
				if(!sib->getLeftChild()->isRed()){
					sib->getRightChild()->setIsRed(false);
					sib->setIsRed(true);
					rotateLeft(sib);
					sib = node->getParent()->getLeftChild();
				}
				sib->setIsRed(node->getParent()->isRed());
				node->getParent()->setIsRed(false);
				sib->getLeftChild()->setIsRed(false);
				rotateRight(node->getParent());
				node = dynamic_cast<RBTNode<key_t, val_t>* >(this->root);
			}
		}
	}
	node->setIsRed(false);
}
  
template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::transplant(BSTNode<key_t, val_t>* nodeToReplace, BSTNode<key_t, val_t>* replacementNode){
	if(nodeToReplace->getParent() == this->sentinel){
		this->root = replacementNode;
	}

	else if(nodeToReplace == nodeToReplace->getParent()->getLeftChild()){
		nodeToReplace->getParent()->setLeftChild(replacementNode);
	}

	else{
		nodeToReplace->getParent()->setRightChild(replacementNode);
	}

	replacementNode->setParent(nodeToReplace->getParent());
}
   
template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> RBTMultimap<key_t, val_t>::remove(const BSTForwardIterator<key_t, val_t>& pos){
	RBTNode<key_t, val_t>* z = dynamic_cast<RBTNode<key_t, val_t>* >(pos.current);
	RBTNode<key_t, val_t>* y = z;
	RBTNode<key_t, val_t>* x;
	BSTForwardIterator<key_t, val_t> temp(pos.current, this->sentinel);
	temp.next();
	bool y_original_color = y->isRed();
	if(z->getLeftChild() == this->sentinel){
		x = z->getRightChild();
		transplant(z,z->getRightChild());
	}
	else if(z->getRightChild() == this->sentinel){
		x = z->getLeftChild();
		transplant(z,z->getLeftChild());
	}
	else{
		y = z->getRightChild();
		while(y->getLeftChild() != this->sentinel && y != this->sentinel)
            y = y->getLeftChild();
		y_original_color = y->isRed();
		x = y->getRightChild();
		if(y->getParent() == z){
			x->setParent(y); 
		}
		else{
			transplant(y, y->getRightChild());
			y->setRightChild(z->getRightChild());
			y->getRightChild()->setParent(y);
		}
		transplant(z,y);
		y->setLeftChild(z->getLeftChild());
		y->getLeftChild()->setParent(y);
		y->setIsRed(z->isRed());
	}
	if(!y_original_color){
		deleteFixup(x);
	}
	if(z != this->sentinel)
        delete z;
	this->numItems--;
	return temp;
	
}


/*
template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::printDOT(std::string filename)
{
   using namespace std;
   ofstream fout(filename.c_str());

   long long counter = 1;
   map<RBTNode<key_t, val_t>*, long long> nodeToCounter;
   nodeToCounter[dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel)] = counter;
   counter++;

   fout << "digraph RBTMultimap {" << endl;

   fout << "\t node" << nodeToCounter[dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel)] << " [label=\"nil\", style=filled, color=grey, fontcolor=white];" << endl;

   if(this->root != this->sentinel)
   {
      RBTNode<key_t, val_t>* rt = dynamic_cast<RBTNode<key_t, val_t>* >(this->root);
      if(!nodeToCounter[rt])
      {
	 nodeToCounter[rt] = counter;
	 counter++;
      }
      if(!nodeToCounter[rt->getParent()])
      {
	 nodeToCounter[rt->getParent()] = counter;
	 counter++;
      }
      fout << "\t node" << nodeToCounter[rt] << " -> node" << nodeToCounter[rt->getParent()] << " [constraint=false, tailport=n, headport=s";
      if(rt->getParent() == this->sentinel)
      {
	 fout << ", color=grey];" << endl;
      }
      else
      {
	 //The root's parent is something weird!! Make the arrow orange so it sticks out
	 fout << ", color=orange];" << endl;
      }

      map<RBTNode<key_t, val_t>*, bool> printed;
   
      queue<RBTNode<key_t, val_t>* > q;
      q.push(rt);
      while(!q.empty())
      {
	 RBTNode<key_t, val_t>* node = q.front();
	 q.pop();

	 printed[node] = true;
      
	 //Set up node's appearance
	 if(!nodeToCounter[node])
	 {
	    nodeToCounter[node] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " [label=\"k: " << node->getKey() << "\", style=filled, color=";
	 if(node->isRed())
	 {
	    fout << "red";
	 }
	 else
	 {
	    fout << "black, fontcolor=white";
	 }
	 fout << "];" << endl;

	 //Set up child links
	 //First the left node
	 if(!nodeToCounter[node->getLeftChild()])
	 {
	    nodeToCounter[node->getLeftChild()] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " -> node" << nodeToCounter[node->getLeftChild()] << " [tailport=sw";    
	 if(node->getLeftChild() == this->sentinel)
	 {
	    fout << ", color=grey";
	 }
	 else if(printed[node->getLeftChild()])
	 {
	    fout << ", color=orange";
	 }
	 else
	 {
	    q.push(node->getLeftChild());
	 }

	 if(node->getLeftChild() != this->sentinel)
	 {
	    if(node->getLeftChild()->getParent() == node)
	    {
	       //The child's parent pointer points right back,
	       //so draw the second arrow
	       fout << ", dir=both];" << endl;
	    }
	    else
	    {
	       //The child node's parent pointer is not correct!
	       //Draw it in orange so it sticks out
	       fout << "];" << endl;
	       if(!nodeToCounter[node->getLeftChild()->getParent()])
	       {
		  nodeToCounter[node->getLeftChild()->getParent()] = counter;
		  counter++;
	       }
	       fout << "\t node" << nodeToCounter[node->getLeftChild()] << " -> node" << nodeToCounter[node->getLeftChild()->getParent()] << " [tailport=n, color=orange];" << endl;
	    }
	 }
	 else
	 {
	    fout << "];" << endl;
	 }

	 //Now the right node
	 if(!nodeToCounter[node->getRightChild()])
	 {
	    nodeToCounter[node->getRightChild()] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " -> node" << nodeToCounter[node->getRightChild()] << " [tailport=se";    
	 if(node->getRightChild() == this->sentinel)
	 {
	    fout << ", color=grey";
	 }
	 else if(printed[node->getRightChild()])
	 {
	    fout << ", color=orange";
	 }
	 else
	 {
	    q.push(node->getRightChild());
	 }

	 if(node->getRightChild() != this->sentinel)
	 {
	    if(node->getRightChild()->getParent() == node)
	    {
	       //The child's parent pointer points right back,
	       //so draw the second arrow
	       fout << ", dir=both];" << endl;
	    }
	    else
	    {
	       //The child node's parent pointer is not correct!
	       //Draw it in orange so it sticks out
	       fout << "];" << endl;
	       if(!nodeToCounter[node->getRightChild()->getParent()])
	       {
		  nodeToCounter[node->getRightChild()->getParent()] = counter;
		  counter++;
	       }
	       fout << "\t node" << nodeToCounter[node->getRightChild()] << " -> node" << nodeToCounter[node->getRightChild()->getParent()] << " [tailport=n, color=orange];" << endl;
	    }
	 }
	 else
	 {
	    fout << "];" << endl;
	 }
      }
   }
   fout << "}" << endl;
}

*/