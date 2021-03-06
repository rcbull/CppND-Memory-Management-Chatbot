#include "graphnode.h"
#include "graphedge.h"

GraphNode::GraphNode(int id) {
  _id = id;
  _chatBot = new ChatBot();
}

GraphNode::~GraphNode() {
  //// STUDENT CODE
  ////

  delete _chatBot;

  ////
  //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token) { 
  _answers.push_back(token); 
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge) {
  _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) {
  _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot) {
  _chatBot = std::move(chatbot);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
  newNode->MoveChatbotHere(std::move(_chatBot));

  delete _chatBot;
  _chatBot = new ChatBot();
}

////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) {
  //// STUDENT CODE
  ////

  // get value from smart pointer
  return _childEdges[index].get();

  ////
  //// EOF STUDENT CODE
}
