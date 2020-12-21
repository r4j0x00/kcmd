/**
 * @file MainWindow.cpp
 * @author Lawrence Warren (lawrencewarren2@gmail.com)
 * @brief The definition of the class `MainWindow` and all of it's related
 * functions and members.
 * @version 0.1
 * @date 2020-11-27
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * https://www.gnu.org/copyleft/gpl.html
 *
 * @copyright Copyright (c) 2020
 *
 */

#include "MainWindow.h"
#include <gdkmm/rgba.h>
#include <gtkmm/cssprovider.h>
#include <gtkmm/frame.h>
#include <iostream>
#include <string>
#include "../models/KoMo2Model.h"

/**
 * @brief Construct a new MainWindow object.
 */
MainWindow::MainWindow()
    : selectAndLoadContainer(),
      compileAndLoadButton("Compile & Load"),
      browseButton("Select File") {
  set_border_width(10);
  set_default_size(1150, 725);

  browseButton.set_size_request(compileAndLoadButton.get_width(),
                                compileAndLoadButton.get_height());

  selectAndLoadContainer.set_layout(Gtk::BUTTONBOX_EDGE);
  selectAndLoadContainer.pack_end(*getBrowseButton(), false, false);
  selectAndLoadContainer.pack_end(*getSelectedFileLabel(), false, false);
  selectAndLoadContainer.pack_end(*getCompileAndLoadButton(), false, false);
  selectAndLoadContainer.show_all_children();

  add(selectAndLoadContainer);
  selectAndLoadContainer.show();
}

MainWindow::~MainWindow() {}

/**
 * @brief Sets the CSS attributes for the views.
 */
void MainWindow::setCSS() {
  // Create a css provider, get the style context, load the css file
  auto ctx = get_style_context();
  auto css = Gtk::CssProvider::create();
  css->load_from_path(getModel()->getAbsolutePathToProjectRoot() +
                      "src/kmdSrc/styles.css");

  // Adds a CSS class for the compile load container
  selectAndLoadContainer.set_name("compileLoadContainer");
  selectAndLoadContainer.get_style_context()->add_class("compileLoadContainer");

  // Adds a CSS class for the buttons
  compileAndLoadButton.set_name("compButtons");
  browseButton.set_name("compButtons");
  compileAndLoadButton.get_style_context()->add_class("compButtons");
  browseButton.get_style_context()->add_class("compButtons");

  // Adds a CSS class for the label
  selectedFileLabel.set_name("fileLabel");
  selectedFileLabel.get_style_context()->add_class("fileLabel");

  // Add the CSS to the screen
  ctx->add_provider_for_screen(Gdk::Screen::get_default(), css,
                               GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}

// Getters and setters
KoMo2Model* MainWindow::getModel() {
  return model;
}
void MainWindow::setModel(KoMo2Model* val) {
  model = val;
}
Gtk::Button* MainWindow::getCompileAndLoadButton() {
  return &compileAndLoadButton;
}
Gtk::Button* MainWindow::getBrowseButton() {
  return &browseButton;
}
Gtk::Label* MainWindow::getSelectedFileLabel() {
  return &selectedFileLabel;
}
void MainWindow::setSelectedFileLabel(std::string val) {
  getSelectedFileLabel()->set_text(val);
}
