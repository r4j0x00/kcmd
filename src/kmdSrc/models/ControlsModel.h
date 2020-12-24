/**
 * @file ControlsModel.h
 * @author Lawrence Warren (lawrencewarren2@gmail.com)
 * @brief A file containing the definition of the ControlsModel class.
 * @version 0.1
 * @date 2020-12-22
 * @section LICENSE
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * https://www.gnu.org/copyleft/gpl.html
 * @copyright Copyright (c) 2020
 */

#include <gtkmm/button.h>
#include "CompileLoadModel.h"

/**
 * @brief The class definition of the ControlsModel class, a data model which
 * encapsulates all state, data and functionality of the Jimulator controls of
 * The KoMo2 GUI. This model is in keeping with the MVC design pattern, where
 * this class is a Model, the status display label is a View, and the Jimulator
 * control buttons are Controllers.
 */
class ControlsModel : private Model {
 public:
  ControlsModel(Gtk::Button* helpButton,
                Gtk::Button* reloadJimulatorButton,
                Gtk::Button* pauseResumeButton,
                Gtk::Button* singleStepExecuteButton,
                Gtk::Button* haltExecutionButton,
                KoMo2Model* parent);
  ~ControlsModel();

  // Click handlers
  void onHelpClick();
  void onBeginRunJimulatorClick();
  void onReloadJimulatorClick();
  void onPauseResumeClick();
  void onSingleStepExecuteClick();
  void onHaltExecutionClick();

  void changeJimulatorState(JimulatorState newState);

 private:
  /**
   * @brief A pointer to the `helpButton` view.
   */
  Gtk::Button* helpButton;

  /**
   * @brief A pointer to the `reloadJimulatorButton` view.
   */
  Gtk::Button* reloadJimulatorButton;

  /**
   * @brief A pointer to the `pauseResumeButton` view.
   */
  Gtk::Button* pauseResumeButton;

  /**
   * @brief A pointer to the `singleStepButton` view.
   */
  Gtk::Button* singleStepExecuteButton;

  /**
   * @brief A pointer to the `haltExecuteButton` view.
   */
  Gtk::Button* haltExecutionButton;
};