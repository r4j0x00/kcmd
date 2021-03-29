#include <iostream>
#include <regex>
#include "../views/TerminalView.h"
#include "KoMo2Model.h"

TerminalModel::TerminalModel(TerminalView* const view, KoMo2Model* const parent)
    : Model(parent), view(view) {
  view->setModel(this);

  setButtonListener(view->getClearButton(), this, &TerminalModel::onClearClick);
}

void TerminalModel::changeJimulatorState(const JimulatorState newState) {}

void TerminalModel::onClearClick() {
  Jimulator::setBreakpoint(temp);  // TODO: temporary
  temp += 0x4;
  getView()->clearTextView();
}

/**
 * @brief Handles any key press events.
 * @param e The key press event.
 * @return bool true if the key press was handled.
 */
const bool TerminalModel::handleKeyPress(const GdkEventKey* const e) {
  if (not getView()->isFocused()) {
    return false;
  }

  // If tab or right arrow pressed, give clear button focus
  if (e->keyval == GDK_KEY_Tab || e->keyval == GDK_KEY_Right) {
    getView()->getClearButton()->grab_focus();
  }
  // If escape or up arrow pressed, give scroll view focus
  else if (e->keyval == GDK_KEY_Escape || e->keyval == GDK_KEY_Up) {
    getView()->getTextView()->get_parent()->grab_focus();
  }
  // Else send key press to Jimulator...
  else {
    return Jimulator::sendTerminalInputToJimulator(e->keyval);
  }

  return true;
}

/**
 * @brief Gets a pointer to the view object.
 * @return TerminalView* const
 */
TerminalView* const TerminalModel::getView() {
  return view;
}

/**
 * @brief Appends a string to the current text view of the
 * terminal, and scroll to the bottom.
 * @param text The text to append to text view.
 */
void TerminalModel::appendTextToTextView(std::string text) {
  // Append text to the buffer, reset the buffer
  auto buff = getView()->getTextView()->get_buffer();
  buff->insert(buff->end(), text);
  getView()->getTextView()->set_buffer(buff);

  // Scroll to the bottom of the scroll bar
  buff = getView()->getTextView()->get_buffer();
  getView()->getTextView()->scroll_to(buff->create_mark(buff->end(), false));
}

/**
 * @brief Reads for any data from Jimulator.
 * @return const std::string
 */
const std::string TerminalModel::readJimulator() {
  return Jimulator::getJimulatorTerminalMessages();
}
