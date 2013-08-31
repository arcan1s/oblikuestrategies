/***************************************************************************
 *   Copyright (C) %{CURRENT_YEAR} by %{AUTHOR} <%{EMAIL}>                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#include "oblikue-strategies.h"
#include <QPainter>
#include <QFontMetrics>
#include <QSizeF>
#include <KLocale>
#include <QGraphicsLinearLayout>
#include <cstdlib>
#include <KConfigDialog>

#include <plasma/svg.h>
#include <plasma/theme.h>

#include "ui_configwindow.h"

oblikuestrategies::oblikuestrategies(QObject *parent, const QVariantList &args)
  : Plasma::Applet(parent, args)
{
  setBackgroundHints(DefaultBackground);
  setHasConfigurationInterface(true);
}

oblikuestrategies::~oblikuestrategies()
{
  delete m_label;
  delete m_button;
}

void oblikuestrategies::init()
{
  mess_first.append("Abandon normal instruments");
  mess_first.append("Accept advice");
  mess_first.append("Accretion");
  mess_first.append("A line has two sides");
  mess_first.append("Allow an easement (an easement is the abandonment of a stricture)");
  mess_first.append("Are there sections? Consider transitions");
  mess_first.append("Ask people to work against their better judgement");
  mess_first.append("Ask your body");
  mess_first.append("Assemble some of the instruments in a group and treat the group");
  mess_first.append("Balance the consistency principle with the inconsistency principle");
  mess_first.append("Be dirty");
  mess_first.append("Breathe more deeply");
  mess_first.append("Bridges -build -burn");
  mess_first.append("Cascades");
  mess_first.append("Change instrument roles");
  mess_first.append("Change nothing and continue with immaculate consistency");
  mess_first.append("Children's voices -speaking -singing");
  mess_first.append("Cluster analysis");
  mess_first.append("Consider different fading systems");
  mess_first.append("Consult other sources -promising -unpromising");
  mess_first.append("Convert a melodic element into a rhythmic element");
  mess_first.append("Courage!");
  mess_first.append("Cut a vital connection");
  mess_first.append("Decorate, decorate");
  mess_first.append("Define an area as 'safe' and use it as an anchor");
  mess_first.append("Destroy -nothing -the most important thing");
  mess_first.append("Discard an axiom");
  mess_first.append("Disconnect from desire");
  mess_first.append("Discover the recipes you are using and abandon them");
  mess_first.append("Distorting time");
  mess_first.append("Do nothing for as long as possible");
  mess_first.append("Don't be afraid of things because they're easy to do");
  mess_first.append("Don't be frightened of cliches");
  mess_first.append("Don't be frightened to display your talents");
  mess_first.append("Don't break the silence");
  mess_first.append("Don't stress one thing more than another");
  mess_first.append("Do something boring");
  mess_first.append("Do the washing up");
  mess_first.append("Do the words need changing?");
  mess_first.append("Do we need holes?");
  mess_first.append("Emphasise differences");
  mess_first.append("Emphasise repetitions");
  mess_first.append("Emphasise the flaws");
  mess_first.append("Faced with a choice, do both (given by Dieter Rot)");
  mess_first.append("Feedback recordings into an acoustic situation");
  mess_first.append("Fill every beat with something");
  mess_first.append("Get your neck massaged");
  mess_first.append("Ghost echoes");
  mess_first.append("Give the game away");
  mess_first.append("Give way to your worst impulse");
  mess_first.append("Go slowly all the way round the outside");
  mess_first.append("Honor thy error as a hidden intention");
  mess_first.append("How would you have done it?");
  mess_first.append("Humanise something free of error");
  mess_first.append("Imagine the music as a moving chain or caterpillar");
  mess_first.append("Imagine the music as a set of disconnected events");
  mess_first.append("Infinitesimal gradations");
  mess_first.append("Intentions -credibility of -nobility of -humility of");
  mess_first.append("Into the impossible");
  mess_first.append("Is it finished?");
  mess_first.append("Is there something missing?");
  mess_first.append("Is the tuning appropriate?");
  mess_first.append("Just carry on");
  mess_first.append("Left channel, right channel, centre channel");
  mess_first.append("Listen in total darkness, or in a very large room, very quietly");
  mess_first.append("Listen to the quiet voice");
  mess_first.append("Look at a very small object, look at its centre");
  mess_first.append("Look at the order in which you do things");
  mess_first.append("Look closely at the most embarrassing details and amplify them");
  mess_first.append("Lowest common denominator check -single beat -single note -single riff");
  mess_first.append("Make a blank valuable by putting it in an exquisite frame");
  mess_first.append("Make an exhaustive list of everything you might do and do the last thing on the list");
  mess_first.append("Make a sudden, destructive unpredictable action; incorporate");
  mess_first.append("Mechanicalise something idiosyncratic");
  mess_first.append("Mute and continue");
  mess_first.append("Only one element of each kind");
  mess_first.append("(Organic) machinery");
  mess_first.append("Overtly resist change");
  mess_first.append("Put in earplugs");
  mess_first.append("Remember those quiet evenings");
  mess_first.append("Remove ambiguities and convert to specifics");
  mess_first.append("Remove specifics and convert to ambiguities");
  mess_first.append("Repetition is a form of change");
  mess_first.append("Reverse");
  mess_first.append("Short circuit (example; a man eating peas with the idea that they will improve his virility shovels them straight into his lap)");
  mess_first.append("Shut the door and listen from outside");
  mess_first.append("Simple subtraction");
  mess_first.append("Spectrum analysis");
  mess_first.append("Take a break");
  mess_first.append("Take away the elements in order of apparent non-importance");
  mess_first.append("Tape your mouth (given by Ritva Saarikko)");
  mess_first.append("The inconsistency principle");
  mess_first.append("The tape is now the music");
  mess_first.append("Think of the radio");
  mess_first.append("Tidy up");
  mess_first.append("Trust in the you of now");
  mess_first.append("Turn it upside down");
  mess_first.append("Twist the spine");
  mess_first.append("Use an old idea");
  mess_first.append("Use an unacceptable colour");
  mess_first.append("Use fewer notes");
  mess_first.append("Use filters");
  mess_first.append("Use 'unqualified' people");
  mess_first.append("Water");
  mess_first.append("What are you really thinking about just now? Incorporate");
  mess_first.append("What is the reality of the situation?");
  mess_first.append("What mistakes did you make last time?");
  mess_first.append("What would your closest friend do?");
  mess_first.append("What wouldn't you do?");
  mess_first.append("Work at a different speed");
  mess_first.append("You are an engineer");
  mess_first.append("You can only make one dot at a time");
  mess_first.append("You don't have to be ashamed of using your own ideas");

  mess_second.append("Abandon normal instruments");
  mess_second.append("Accept advice");
  mess_second.append("Accretion");
  mess_second.append("A line has two sides");
  mess_second.append("Allow an easement (an easement is the abandonment of a stricture)");
  mess_second.append("Always first steps");
  mess_second.append("Always give yourself credit for having more than personality (given by Arto Lindsay)");
  mess_second.append("Are there sections? Consider transitions");
  mess_second.append("Ask people to work against their better judgement");
  mess_second.append("Ask your body");
  mess_second.append("Assemble some of the instruments in a group and treat the group");
  mess_second.append("A very small object -Its centre");
  mess_second.append("Balance the consistency principle with the inconsistency principle");
  mess_second.append("Be dirty");
  mess_second.append("Be extravagant");
  mess_second.append("Breathe more deeply");
  mess_second.append("Bridges -build -burn");
  mess_second.append("Cascades");
  mess_second.append("Change instrument roles");
  mess_second.append("Change nothing and continue with immaculate consistency");
  mess_second.append("Children's voices -speaking -singing");
  mess_second.append("Cluster analysis");
  mess_second.append("Consider different fading systems");
  mess_second.append("Consult other sources -promising -unpromising");
  mess_second.append("Convert a melodic element into a rhythmic element");
  mess_second.append("Courage!");
  mess_second.append("Cut a vital connection");
  mess_second.append("Decorate, decorate");
  mess_second.append("Define an area as 'safe' and use it as an anchor");
  mess_second.append("Destroy -nothing -the most important thing");
  mess_second.append("Discard an axiom");
  mess_second.append("Disciplined self-indulgence");
  mess_second.append("Disconnect from desire");
  mess_second.append("Discover the recipes you are using and abandon them");
  mess_second.append("Distorting time");
  mess_second.append("Do nothing for as long as possible");
  mess_second.append("Don't be afraid of things because they're easy to do");
  mess_second.append("Don't be frightened of cliches");
  mess_second.append("Don't be frightened to display your talents");
  mess_second.append("Don't break the silence");
  mess_second.append("Don't stress *on* thing more than another (sic)");
  mess_second.append("Do something boring");
  mess_second.append("Do the washing up");
  mess_second.append("Do the words need changing?");
  mess_second.append("Do we need holes?");
  mess_second.append("Emphasise differences");
  mess_second.append("Emphasise repetitions");
  mess_second.append("Emphasise the flaws");
  mess_second.append("Faced with a choice, do both (given by Dieter Rot)");
  mess_second.append("Feed the recording back out of the medium");
  mess_second.append("Fill every beat with something");
  mess_second.append("Get your neck massaged");
  mess_second.append("Ghost echoes");
  mess_second.append("Give the game away");
  mess_second.append("Give way to your worst impulse");
  mess_second.append("Go outside. Shut the door.");
  mess_second.append("Go slowly all the way round the outside");
  mess_second.append("Honor thy error as a hidden intention");
  mess_second.append("How would you have done it?");
  mess_second.append("Humanise something free of error");
  mess_second.append("Idiot glee (?)");
  mess_second.append("Imagine the piece as a set of disconnected events");
  mess_second.append("Infinitesimal gradations");
  mess_second.append("Intentions -credibility of -nobility of -humility of");
  mess_second.append("In total darkness, or in a very large room, very quietly");
  mess_second.append("Into the impossible");
  mess_second.append("Is it finished?");
  mess_second.append("Is the tuning intonation correct?");
  mess_second.append("Is there something missing?");
  mess_second.append("It is quite possible (after all)");
  mess_second.append("Just carry on");
  mess_second.append("Left channel, right channel, centre channel");
  mess_second.append("Listen to the quiet voice");
  mess_second.append("Look at the order in which you do things");
  mess_second.append("Look closely at the most embarrassing details and amplify them");
  mess_second.append("Lost in useless territory");
  mess_second.append("Lowest common denominator");
  mess_second.append("Make a blank valuable by putting it in an exquisite frame");
  mess_second.append("Make an exhaustive list of everything you might do and do the last thing on the list");
  mess_second.append("Make a sudden, destructive unpredictable action; incorporate");
  mess_second.append("Mechanicalise something idiosyncratic");
  mess_second.append("Mute and continue");
  mess_second.append("Not building a wall but making a brick");
  mess_second.append("Only one element of each kind");
  mess_second.append("(Organic) machinery");
  mess_second.append("Overtly resist change");
  mess_second.append("Put in earplugs");
  mess_second.append("Question the heroic approach");
  mess_second.append("Remember those quiet evenings");
  mess_second.append("Remove ambiguities and convert to specifics");
  mess_second.append("Remove specifics and convert to ambiguities");
  mess_second.append("Repetition is a form of change");
  mess_second.append("Revaluation (a warm feeling)");
  mess_second.append("Reverse");
  mess_second.append("Short circuit (example; a man eating peas with the idea that they will improve his virility shovels them straight into his lap)");
  mess_second.append("Simple subtraction");
  mess_second.append("Simply a matter of work");
  mess_second.append("Spectrum analysis");
  mess_second.append("State the problem in words as simply as possible");
  mess_second.append("Take a break");
  mess_second.append("Take away the elements in order of apparent non-importance");
  mess_second.append("Tape your mouth (given by Ritva Saarikko)");
  mess_second.append("The inconsistency principle");
  mess_second.append("The most important thing is the thing most easily forgotten");
  mess_second.append("The tape is now the music");
  mess_second.append("Think of the radio");
  mess_second.append("Tidy up");
  mess_second.append("Towards the insignificant");
  mess_second.append("Trust in the you of now");
  mess_second.append("Turn it upside down");
  mess_second.append("Twist the spine");
  mess_second.append("Use an old idea");
  mess_second.append("Use an unacceptable colour");
  mess_second.append("Use fewer notes");
  mess_second.append("Use filters");
  mess_second.append("Use 'unqualified' people");
  mess_second.append("Water");
  mess_second.append("What are the sections sections of? Imagine a caterpillar moving");
  mess_second.append("What are you really thinking about just now?");
  mess_second.append("What is the reality of the situation?");
  mess_second.append("What mistakes did you make last time?");
  mess_second.append("What would your closest friend do?");
  mess_second.append("What wouldn't you do?");
  mess_second.append("What would your closest friend do?");
  mess_second.append("Work at a different speed");
  mess_second.append("You are an engineer");
  mess_second.append("You can only make one dot at a time");
  mess_second.append("You don't have to be ashamed of using your own ideas");

  mess_third.append("Abandon normal instruments");
  mess_third.append("Accept advice");
  mess_third.append("Accretion");
  mess_third.append("A line has two sides");
  mess_third.append("Allow an easement (an easement is the abandonment of a stricture)");
  mess_third.append("Always first steps");
  mess_third.append("Are there sections? Consider transitions");
  mess_third.append("Ask people to work against their better judgement");
  mess_third.append("Ask your body");
  mess_third.append("Assemble some of the elements in a group and treat the group");
  mess_third.append("Balance the consistency principle with the inconsistency principle");
  mess_third.append("Be dirty");
  mess_third.append("Be extravagant");
  mess_third.append("Be less critical more often");
  mess_third.append("Breathe more deeply");
  mess_third.append("Bridges -build -burn");
  mess_third.append("Cascades");
  mess_third.append("Change instrument roles");
  mess_third.append("Change nothing and continue with immaculate consistency");
  mess_third.append("Children -speaking -singing");
  mess_third.append("Cluster analysis");
  mess_third.append("Consider different fading systems");
  mess_third.append("Consult other sources -promising -unpromising");
  mess_third.append("Courage!");
  mess_third.append("Cut a vital connection");
  mess_third.append("Decorate, decorate");
  mess_third.append("Define an area as 'safe' and use it as an anchor");
  mess_third.append("Destroy -nothing -the most important thing");
  mess_third.append("Discard an axiom");
  mess_third.append("Disciplined self-indulgence");
  mess_third.append("Disconnect from desire");
  mess_third.append("Discover the recipes you are using and abandon them");
  mess_third.append("Distorting time");
  mess_third.append("Do nothing for as long as possible");
  mess_third.append("Don't be afraid of things because they're easy to do");
  mess_third.append("Don't be frightened of cliches");
  mess_third.append("Don't be frightened to display your talents");
  mess_third.append("Don't break the silence");
  mess_third.append("Don't stress one thing more than another");
  mess_third.append("Do something boring");
  mess_third.append("Do the words need changing?");
  mess_third.append("Do we need holes?");
  mess_third.append("Emphasise differences");
  mess_third.append("Emphasise repetitions");
  mess_third.append("Emphasise the flaws");
  mess_third.append("Fill every beat with something");
  mess_third.append("From nothing to more than nothing");
  mess_third.append("Ghost echoes");
  mess_third.append("Give the game away");
  mess_third.append("Give way to your worst impulse");
  mess_third.append("Go outside. Shut the door.");
  mess_third.append("Go slowly all the way round the outside");
  mess_third.append("Go to an extreme, move back to a more comfortable place");
  mess_third.append("Honor thy error as a hidden intention");
  mess_third.append("How would you have done it?");
  mess_third.append("Humanise something free of error");
  mess_third.append("Idiot glee (?)");
  mess_third.append("Imagine the piece as a set of disconnected events");
  mess_third.append("Infinitesimal gradations");
  mess_third.append("Intentions -nobility of -humility of -credibility of");
  mess_third.append("In total darkness, or in a very large room, very quietly");
  mess_third.append("Into the impossible");
  mess_third.append("Is it finished?");
  mess_third.append("Is the intonation correct?");
  mess_third.append("Is there something missing?");
  mess_third.append("It is quite possible (after all)");
  mess_third.append("Just carry on");
  mess_third.append("Listen to the quiet voice");
  mess_third.append("Look at the order in which you do things");
  mess_third.append("Look closely at the most embarrassing details and amplify them");
  mess_third.append("Lost in useless territory");
  mess_third.append("Lowest common denominator");
  mess_third.append("Make a blank valuable by putting it in an exquisite frame");
  mess_third.append("Make an exhaustive list of everything you might do and do the last thing on the list");
  mess_third.append("Make a sudden, destructive unpredictable action; incorporate");
  mess_third.append("Mechanicalise something idiosyncratic");
  mess_third.append("Mute and continue");
  mess_third.append("Not building a wall but making a brick");
  mess_third.append("Once the search is in progress, something will be found");
  mess_third.append("Only a part, not the whole");
  mess_third.append("Only one element of each kind");
  mess_third.append("(Organic) machinery");
  mess_third.append("Overtly resist change");
  mess_third.append("Question the heroic approach");
  mess_third.append("Remember those quiet evenings");
  mess_third.append("Remove ambiguities and convert to specifics");
  mess_third.append("Remove specifics and convert to ambiguities");
  mess_third.append("Repetition is a form of change");
  mess_third.append("Retrace your steps");
  mess_third.append("Revaluation (a warm feeling)");
  mess_third.append("Reverse");
  mess_third.append("Short circuit (example; a man eating peas with the idea that they will improve his virility shovels them straight into his lap)");
  mess_third.append("Simple subtraction");
  mess_third.append("Simply a matter of work");
  mess_third.append("State the problem in words as clearly as possible");
  mess_third.append("Take a break");
  mess_third.append("Take away the elements in order of apparent non-importance");
  mess_third.append("The inconsistency principle");
  mess_third.append("The most important thing is the thing most easily forgotten");
  mess_third.append("The tape is now the music");
  mess_third.append("Think of the radio");
  mess_third.append("Tidy up");
  mess_third.append("Towards the insignificant");
  mess_third.append("Trust in the you of now");
  mess_third.append("Turn it upside down");
  mess_third.append("Use an old idea");
  mess_third.append("Use an unacceptable colour");
  mess_third.append("Use fewer notes");
  mess_third.append("Use filters");
  mess_third.append("Use 'unqualified' people");
  mess_third.append("Water");
  mess_third.append("What are the sections sections of? Imagine a caterpillar moving");
  mess_third.append("What are you really thinking about just now?");
  mess_third.append("What is the reality of the situation?");
  mess_third.append("What mistakes did you make last time?");
  mess_third.append("What wouldn't you do?");
  mess_third.append("What would your closest friend do?");
  mess_third.append("Work at a different speed");
  mess_third.append("Would anybody want it?");
  mess_third.append("You are an engineer");
  mess_third.append("You can only make one dot at a time");
  mess_third.append("You don't have to be ashamed of using your own ideas");

  mess_fouth.append("Abandon desire");
  mess_fouth.append("Abandon normal instructions");
  mess_fouth.append("Accept advice");
  mess_fouth.append("Adding on");
  mess_fouth.append("A line has two sides");
  mess_fouth.append("Always the first steps");
  mess_fouth.append("Ask people to work against their better judgement");
  mess_fouth.append("Ask your body");
  mess_fouth.append("Be dirty");
  mess_fouth.append("Be extravagant");
  mess_fouth.append("Be less critical");
  mess_fouth.append("Breathe more deeply");
  mess_fouth.append("Bridges -build -burn");
  mess_fouth.append("Change ambiguities to specifics");
  mess_fouth.append("Change nothing and continue consistently");
  mess_fouth.append("Change specifics to ambiguities");
  mess_fouth.append("Consider transitions");
  mess_fouth.append("Courage!");
  mess_fouth.append("Cut a vital connection");
  mess_fouth.append("Decorate, decorate");
  mess_fouth.append("Destroy nothing; Destroy the most important thing");
  mess_fouth.append("Discard an axiom");
  mess_fouth.append("Disciplined self-indulgence");
  mess_fouth.append("Discover your formulas and abandon them");
  mess_fouth.append("Display your talent");
  mess_fouth.append("Distort time");
  mess_fouth.append("Do nothing for as long as possible");
  mess_fouth.append("Don't avoid what is easy");
  mess_fouth.append("Don't break the silence");
  mess_fouth.append("Don't stress one thing more than another");
  mess_fouth.append("Do something boring");
  mess_fouth.append("Do something sudden, destructive and unpredictable");
  mess_fouth.append("Do the last thing first");
  mess_fouth.append("Do the words need changing?");
  mess_fouth.append("Emphasize differences");
  mess_fouth.append("Emphasize the flaws");
  mess_fouth.append("Faced with a choice, do both (from Dieter Rot)");
  mess_fouth.append("Find a safe part and use it as an anchor");
  mess_fouth.append("Give the game away");
  mess_fouth.append("Give way to your worst impulse");
  mess_fouth.append("Go outside. Shut the door.");
  mess_fouth.append("Go to an extreme, come part way back");
  mess_fouth.append("How would someone else do it?");
  mess_fouth.append("How would you have done it?");
  mess_fouth.append("In total darkness, or in a very large room, very quietly");
  mess_fouth.append("Is it finished?");
  mess_fouth.append("Is something missing?");
  mess_fouth.append("Is the style right?");
  mess_fouth.append("It is simply a matter or work");
  mess_fouth.append("Just carry on");
  mess_fouth.append("Listen to the quiet voice");
  mess_fouth.append("Look at the order in which you do things");
  mess_fouth.append("Magnify the most difficult details");
  mess_fouth.append("Make it more sensual");
  mess_fouth.append("Make what's perfect more human");
  mess_fouth.append("Move towards the unimportant");
  mess_fouth.append("Not building a wall; making a brick");
  mess_fouth.append("Once the search has begun, something will be found");
  mess_fouth.append("Only a part, not the whole");
  mess_fouth.append("Only one element of each kind");
  mess_fouth.append("Openly resist change");
  mess_fouth.append("Pae White's non-blank graphic metacard");
  mess_fouth.append("Question the heroic");
  mess_fouth.append("Remember quiet evenings");
  mess_fouth.append("Remove a restriction");
  mess_fouth.append("Repetition is a form of change");
  mess_fouth.append("Retrace your steps");
  mess_fouth.append("Reverse");
  mess_fouth.append("Simple Subtraction");
  mess_fouth.append("Slow preparation, fast execution");
  mess_fouth.append("State the problem as clearly as possible");
  mess_fouth.append("Take a break");
  mess_fouth.append("Take away the important parts");
  mess_fouth.append("The inconsistency principle");
  mess_fouth.append("The most easily forgotten thing is the most important");
  mess_fouth.append("Think - inside the work -outside the work");
  mess_fouth.append("Tidy up");
  mess_fouth.append("Try faking it (from Stewart Brand)");
  mess_fouth.append("Turn it upside down");
  mess_fouth.append("Use an old idea");
  mess_fouth.append("Use cliches");
  mess_fouth.append("Use filters");
  mess_fouth.append("Use something nearby as a model");
  mess_fouth.append("Use 'unqualified' people");
  mess_fouth.append("Use your own ideas");
  mess_fouth.append("Voice your suspicions");
  mess_fouth.append("Water");
  mess_fouth.append("What context would look right?");
  mess_fouth.append("What is the simplest solution?");
  mess_fouth.append("What mistakes did you make last time?");
  mess_fouth.append("What to increase? What to reduce? What to maintain?");
  mess_fouth.append("What were you really thinking about just now?");
  mess_fouth.append("What wouldn't you do?");
  mess_fouth.append("What would your closest friend do?");
  mess_fouth.append("When is it for?");
  mess_fouth.append("Where is the edge?");
  mess_fouth.append("Which parts can be grouped?");
  mess_fouth.append("Work at a different speed");
  mess_fouth.append("Would anyone want it?");
  mess_fouth.append("Your mistake was a hidden intention");

  QGraphicsLinearLayout *layout = new QGraphicsLinearLayout(this);
  layout->setOrientation(Qt::Vertical);

  m_label = new Plasma::Label(this);
  layout->addItem(m_label);

  m_button = new Plasma::PushButton(this);
  m_button->setMinimumSize(40.0, 20.0);
  m_button->setMaximumSize(80.0, 30.0);
  m_button->setText("Update");
  layout->addItem(m_button);

  connect(m_button, SIGNAL(clicked()), this, SLOT(updateEvent()));

  formatLine.append("");
  formatLine.append("");
  configChanged();
}

void oblikuestrategies::updateEvent()
{
  if (edition == 1)
  {
    int num = rand() % mess_first.count();
    m_label->setText(formatLine[0] + mess_first[num] + formatLine[1]);
  }
  else if (edition == 2)
  {
    int num = rand() % mess_second.count();
    m_label->setText(formatLine[0] + mess_second[num] + formatLine[1]);
  }
  else if (edition == 3)
  {
    int num = rand() % mess_third.count();
    m_label->setText(formatLine[0] + mess_third[num] + formatLine[1]);
  }
  else if (edition == 4)
  {
    int num = rand() % mess_fouth.count();
    m_label->setText(formatLine[0] + mess_fouth[num] + formatLine[1]);
  }
}

void oblikuestrategies::createConfigurationInterface(KConfigDialog *parent)
{
  QWidget *configwin = new QWidget;
  uiConfig.setupUi(configwin);

  uiConfig.comboBox_edition->setCurrentIndex(edition-1);
  QFont font = QFont(fontFamily, 12, 400, FALSE);
  uiConfig.fontComboBox_font->setCurrentFont(font);
  uiConfig.spinBox_fontSize->setValue(fontSize);
  uiConfig.kcolorcombo_fontColor->setColor(fontColor);
  if (fontStyle == "normal")
    uiConfig.comboBox_fontStyle->setCurrentIndex(0);
  else if (fontStyle == "italic")
    uiConfig.comboBox_fontStyle->setCurrentIndex(1);
  uiConfig.spinBox_fontWeight->setValue(fontWeight);

  parent->addPage(configwin, i18n("Appearance"), Applet::icon());
  connect(parent, SIGNAL(okClicked()), this, SLOT(configAccepted()));
  connect(parent, SIGNAL(applyClicked()), this, SLOT(configAccepted()));
}

void oblikuestrategies::configAccepted()
{
  KConfigGroup cg = config();

  cg.writeEntry("edition", uiConfig.comboBox_edition->currentIndex()+1);
  cg.writeEntry("font_family", uiConfig.fontComboBox_font->currentFont().family());
  cg.writeEntry("font_size", uiConfig.spinBox_fontSize->value());
  cg.writeEntry("font_color", uiConfig.kcolorcombo_fontColor->color().name());
  cg.writeEntry("font_style", uiConfig.comboBox_fontStyle->currentText());
  cg.writeEntry("font_weight", uiConfig.spinBox_fontSize->value());
}

void oblikuestrategies::configChanged()
{
  KConfigGroup cg = config();

  edition = cg.readEntry("edition", 1);
  fontFamily = cg.readEntry("font_family", "Terminus");
  fontSize = cg.readEntry("font_size", 12);
  fontColor = cg.readEntry("font_color", "#000000");
  fontStyle = cg.readEntry("font_style", "normal");
  fontWeight = cg.readEntry("font_weight", 400);
  formatLine[0] = ("<p align=\"justify\"><span style=\" font-family:'" + fontFamily + \
                   "'; font-style:" + fontStyle + \
                   "; font-size:" + QString::number(fontSize) + \
                   "pt; font-weight:" + QString::number(fontWeight) + \
                   "; color:" + fontColor + \
                   ";\">");
  formatLine[1] = ("</span></p>");

  updateEvent();
}

#include "oblikue-strategies.moc"
