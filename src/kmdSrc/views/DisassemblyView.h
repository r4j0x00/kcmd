/**
 * @file DisassemblyView.h
 * @author Lawrence Warren (lawrencewarren2@gmail.com)
 * @brief This file contains the header file for the DisassemblyRows and
 * DisassemblyView classes.
 * @version 0.1
 * @date 2021-03-18
 * @section LICENSE
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details at
 * https://www.gnu.org/copyleft/gpl.html
 */

#include <gtkmm/buttonbox.h>
#include <gtkmm/eventbox.h>
#include <gtkmm/grid.h>
#include <gtkmm/label.h>
#include <gtkmm/togglebutton.h>
#include <iostream>
#include <string>
#include <vector>

class MainWindowView;
class DisassemblyModel;
class MemoryValues;

/**
 * @brief A single instance of this class represents a single read memory
 * address and the associated data - this is shown as a single row in the
 * disassembly window.
 */
class DisassemblyRows : public Gtk::HButtonBox {
 public:
  DisassemblyRows();
  void setBreakpoint(const bool text);
  void setAddress(const std::string text);
  void setHex(const std::string text);
  void setDisassembly(const std::string text);

 private:
  /**
   * @brief The debugging breakpoint button.
   */
  Gtk::ToggleButton breakpoint;
  /**
   * @brief Displays the address of the current memory value.
   */
  Gtk::Label address;
  /**
   * @brief Displays the current hexadecimal value of the memory.
   */
  Gtk::Label hex;
  /**
   * @brief Displays the current disassembly value of the memory.
   */
  Gtk::Label disassembly;

 private:
  // ! Deleted special member functions
  // stops these functions from being misused, creates a sensible error
  DisassemblyRows(const DisassemblyRows&) = delete;
  DisassemblyRows(const DisassemblyRows&&) = delete;
  DisassemblyRows& operator=(const DisassemblyRows&) = delete;
  DisassemblyRows& operator=(const DisassemblyRows&&) = delete;
};

/**
 * @brief Represents the entire disassembly window in the overall KoMo2 GUI.
 * Contains several rows of memory values, buttons for navigation, and buttons
 * for debugging.
 * This class inherits from EventBox, which allows for interception of scroll
 * events, and therefore programmer defined handling of these events. This
 * handling of scroll events is done in the function
 * `DisassemblyModel::handleScroll(GdkEventScroll* e)`.
 */
class DisassemblyView : public Gtk::EventBox {
 public:
  DisassemblyView(MainWindowView* const parent);
  void refreshViews(std::array<MemoryValues, 15> vals);

  // ! Getters and setters

  void setModel(DisassemblyModel* const val);
  DisassemblyModel* const getModel() const;
  Gtk::VButtonBox* const getNavigationButtons();
  Gtk::VButtonBox* const getDisassemblyContainer();
  Gtk::HButtonBox* const getContainer();
  std::vector<DisassemblyRows>* const getRows();

 private:
  // ! Member children
  /**
   * @brief A pointer to the parent view.
   */
  MainWindowView* parent;
  /**
   * @brief A pointer to the related model.
   */
  DisassemblyModel* model;

  // ! GUI children

  /**
   * @brief A container for the 6 navigation buttons.
   */
  Gtk::VButtonBox navigationButtons;
  /**
   * @brief A container for the disassembly rows.
   */
  Gtk::VButtonBox disassemblyContainer;
  /**
   * @brief The master container for the entire view, and the sole child of the
   * EventBox.
   */
  Gtk::HButtonBox container;
  /**
   * @brief An array of 15 rows. Each array entry represents a row of memory
   * values within the memory window.
   */
  std::vector<DisassemblyRows> rows{std::vector<DisassemblyRows>(15)};

  // ! Functions

  void initDisassemblyContainer();
  void packView();

  // ! Deleted special member functions
  // stops these functions from being misused, creates a sensible error
  DisassemblyView(const DisassemblyView&) = delete;
  DisassemblyView(const DisassemblyView&&) = delete;
  DisassemblyView& operator=(const DisassemblyView&) = delete;
  DisassemblyView& operator=(const DisassemblyView&&) = delete;
};
