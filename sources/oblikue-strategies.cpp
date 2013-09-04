/***************************************************************************
 *   Copyright (C) 2013 by Evgeniy Alekseev <esalekseev@gmail.com>         *
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
#include "ui_configwindow.h"

#include <KConfigDialog>
#include <QGraphicsLinearLayout>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <plasma/theme.h>

#ifdef MSEC_IN_MIN
#undef MSEC_IN_MIN
#endif /* MSEC_IN_MIN */
#define MSEC_IN_MIN 60*1000


oblikuestrategies::oblikuestrategies(QObject *parent, const QVariantList &args)
  : Plasma::Applet(parent, args)
{
  setBackgroundHints(DefaultBackground);
  setHasConfigurationInterface(true);
}

oblikuestrategies::~oblikuestrategies()
{
  delete m_label;
  delete info_label;
  delete timer;
}

void oblikuestrategies::setMessagesText()
{
  QStringList temp_mess;
  //  first edition
  temp_mess.append("Abandon normal instruments");
  temp_mess.append("Accept advice");
  temp_mess.append("Accretion");
  temp_mess.append("A line has two sides");
  temp_mess.append("Allow an easement (an easement is the abandonment of a stricture)");
  temp_mess.append("Are there sections? Consider transitions");
  temp_mess.append("Ask people to work against their better judgement");
  temp_mess.append("Ask your body");
  temp_mess.append("Assemble some of the instruments in a group and treat the group");
  temp_mess.append("Balance the consistency principle with the inconsistency principle");
  temp_mess.append("Be dirty");
  temp_mess.append("Breathe more deeply");
  temp_mess.append("Bridges -build -burn");
  temp_mess.append("Cascades");
  temp_mess.append("Change instrument roles");
  temp_mess.append("Change nothing and continue with immaculate consistency");
  temp_mess.append("Children's voices -speaking -singing");
  temp_mess.append("Cluster analysis");
  temp_mess.append("Consider different fading systems");
  temp_mess.append("Consult other sources -promising -unpromising");
  temp_mess.append("Convert a melodic element into a rhythmic element");
  temp_mess.append("Courage!");
  temp_mess.append("Cut a vital connection");
  temp_mess.append("Decorate, decorate");
  temp_mess.append("Define an area as 'safe' and use it as an anchor");
  temp_mess.append("Destroy -nothing -the most important thing");
  temp_mess.append("Discard an axiom");
  temp_mess.append("Disconnect from desire");
  temp_mess.append("Discover the recipes you are using and abandon them");
  temp_mess.append("Distorting time");
  temp_mess.append("Do nothing for as long as possible");
  temp_mess.append("Don't be afraid of things because they're easy to do");
  temp_mess.append("Don't be frightened of cliches");
  temp_mess.append("Don't be frightened to display your talents");
  temp_mess.append("Don't break the silence");
  temp_mess.append("Don't stress one thing more than another");
  temp_mess.append("Do something boring");
  temp_mess.append("Do the washing up");
  temp_mess.append("Do the words need changing?");
  temp_mess.append("Do we need holes?");
  temp_mess.append("Emphasise differences");
  temp_mess.append("Emphasise repetitions");
  temp_mess.append("Emphasise the flaws");
  temp_mess.append("Faced with a choice, do both (given by Dieter Rot)");
  temp_mess.append("Feedback recordings into an acoustic situation");
  temp_mess.append("Fill every beat with something");
  temp_mess.append("Get your neck massaged");
  temp_mess.append("Ghost echoes");
  temp_mess.append("Give the game away");
  temp_mess.append("Give way to your worst impulse");
  temp_mess.append("Go slowly all the way round the outside");
  temp_mess.append("Honor thy error as a hidden intention");
  temp_mess.append("How would you have done it?");
  temp_mess.append("Humanise something free of error");
  temp_mess.append("Imagine the music as a moving chain or caterpillar");
  temp_mess.append("Imagine the music as a set of disconnected events");
  temp_mess.append("Infinitesimal gradations");
  temp_mess.append("Intentions -credibility of -nobility of -humility of");
  temp_mess.append("Into the impossible");
  temp_mess.append("Is it finished?");
  temp_mess.append("Is there something missing?");
  temp_mess.append("Is the tuning appropriate?");
  temp_mess.append("Just carry on");
  temp_mess.append("Left channel, right channel, centre channel");
  temp_mess.append("Listen in total darkness, or in a very large room, very quietly");
  temp_mess.append("Listen to the quiet voice");
  temp_mess.append("Look at a very small object, look at its centre");
  temp_mess.append("Look at the order in which you do things");
  temp_mess.append("Look closely at the most embarrassing details and amplify them");
  temp_mess.append("Lowest common denominator check -single beat -single note -single riff");
  temp_mess.append("Make a blank valuable by putting it in an exquisite frame");
  temp_mess.append("Make an exhaustive list of everything you might do and do the last thing on the list");
  temp_mess.append("Make a sudden, destructive unpredictable action; incorporate");
  temp_mess.append("Mechanicalise something idiosyncratic");
  temp_mess.append("Mute and continue");
  temp_mess.append("Only one element of each kind");
  temp_mess.append("(Organic) machinery");
  temp_mess.append("Overtly resist change");
  temp_mess.append("Put in earplugs");
  temp_mess.append("Remember .those quiet evenings");
  temp_mess.append("Remove ambiguities and convert to specifics");
  temp_mess.append("Remove specifics and convert to ambiguities");
  temp_mess.append("Repetition is a form of change");
  temp_mess.append("Reverse");
  temp_mess.append("Short circuit (example; a man eating peas with the idea that they will improve his virility shovels them straight into his lap)");
  temp_mess.append("Shut the door and listen from outside");
  temp_mess.append("Simple subtraction");
  temp_mess.append("Spectrum analysis");
  temp_mess.append("Take a break");
  temp_mess.append("Take away the elements in order of apparent non-importance");
  temp_mess.append("Tape your mouth (given by Ritva Saarikko)");
  temp_mess.append("The inconsistency principle");
  temp_mess.append("The tape is now the music");
  temp_mess.append("Think of the radio");
  temp_mess.append("Tidy up");
  temp_mess.append("Trust in the you of now");
  temp_mess.append("Turn it upside down");
  temp_mess.append("Twist the spine");
  temp_mess.append("Use an old idea");
  temp_mess.append("Use an unacceptable colour");
  temp_mess.append("Use fewer notes");
  temp_mess.append("Use filters");
  temp_mess.append("Use 'unqualified' people");
  temp_mess.append("Water");
  temp_mess.append("What are you really thinking about just now? Incorporate");
  temp_mess.append("What is the reality of the situation?");
  temp_mess.append("What mistakes did you make last time?");
  temp_mess.append("What would your closest friend do?");
  temp_mess.append("What wouldn't you do?");
  temp_mess.append("Work at a different speed");
  temp_mess.append("You are an engineer");
  temp_mess.append("You can only make one dot at a time");
  temp_mess.append("You don't have to be ashamed of using your own ideas");
  temp_mess.append("");
  mess.append(temp_mess);
  temp_mess.clear();

  //  second edition
  temp_mess.append("Abandon normal instruments");
  temp_mess.append("Accept advice");
  temp_mess.append("Accretion");
  temp_mess.append("A line has two sides");
  temp_mess.append("Allow an easement (an easement is the abandonment of a stricture)");
  temp_mess.append("Always first steps");
  temp_mess.append("Always give yourself credit for having more than personality (given by Arto Lindsay)");
  temp_mess.append("Are there sections? Consider transitions");
  temp_mess.append("Ask people to work against their better judgement");
  temp_mess.append("Ask your body");
  temp_mess.append("Assemble some of the instruments in a group and treat the group");
  temp_mess.append("A very small object -Its centre");
  temp_mess.append("Balance the consistency principle with the inconsistency principle");
  temp_mess.append("Be dirty");
  temp_mess.append("Be extravagant");
  temp_mess.append("Breathe more deeply");
  temp_mess.append("Bridges -build -burn");
  temp_mess.append("Cascades");
  temp_mess.append("Change instrument roles");
  temp_mess.append("Change nothing and continue with immaculate consistency");
  temp_mess.append("Children's voices -speaking -singing");
  temp_mess.append("Cluster analysis");
  temp_mess.append("Consider different fading systems");
  temp_mess.append("Consult other sources -promising -unpromising");
  temp_mess.append("Convert a melodic element into a rhythmic element");
  temp_mess.append("Courage!");
  temp_mess.append("Cut a vital connection");
  temp_mess.append("Decorate, decorate");
  temp_mess.append("Define an area as 'safe' and use it as an anchor");
  temp_mess.append("Destroy -nothing -the most important thing");
  temp_mess.append("Discard an axiom");
  temp_mess.append("Disciplined self-indulgence");
  temp_mess.append("Disconnect from desire");
  temp_mess.append("Discover the recipes you are using and abandon them");
  temp_mess.append("Distorting time");
  temp_mess.append("Do nothing for as long as possible");
  temp_mess.append("Don't be afraid of things because they're easy to do");
  temp_mess.append("Don't be frightened of cliches");
  temp_mess.append("Don't be frightened to display your talents");
  temp_mess.append("Don't break the silence");
  temp_mess.append("Don't stress *on* thing more than another (sic)");
  temp_mess.append("Do something boring");
  temp_mess.append("Do the washing up");
  temp_mess.append("Do the words need changing?");
  temp_mess.append("Do we need holes?");
  temp_mess.append("Emphasise differences");
  temp_mess.append("Emphasise repetitions");
  temp_mess.append("Emphasise the flaws");
  temp_mess.append("Faced with a choice, do both (given by Dieter Rot)");
  temp_mess.append("Feed the recording back out of the medium");
  temp_mess.append("Fill every beat with something");
  temp_mess.append("Get your neck massaged");
  temp_mess.append("Ghost echoes");
  temp_mess.append("Give the game away");
  temp_mess.append("Give way to your worst impulse");
  temp_mess.append("Go outside. Shut the door.");
  temp_mess.append("Go slowly all the way round the outside");
  temp_mess.append("Honor thy error as a hidden intention");
  temp_mess.append("How would you have done it?");
  temp_mess.append("Humanise something free of error");
  temp_mess.append("Idiot glee (?)");
  temp_mess.append("Imagine the piece as a set of disconnected events");
  temp_mess.append("Infinitesimal gradations");
  temp_mess.append("Intentions -credibility of -nobility of -humility of");
  temp_mess.append("In total darkness, or in a very large room, very quietly");
  temp_mess.append("Into the impossible");
  temp_mess.append("Is it finished?");
  temp_mess.append("Is the tuning intonation correct?");
  temp_mess.append("Is there something missing?");
  temp_mess.append("It is quite possible (after all)");
  temp_mess.append("Just carry on");
  temp_mess.append("Left channel, right channel, centre channel");
  temp_mess.append("Listen to the quiet voice");
  temp_mess.append("Look at the order in which you do things");
  temp_mess.append("Look closely at the most embarrassing details and amplify them");
  temp_mess.append("Lost in useless territory");
  temp_mess.append("Lowest common denominator");
  temp_mess.append("Make a blank valuable by putting it in an exquisite frame");
  temp_mess.append("Make an exhaustive list of everything you might do and do the last thing on the list");
  temp_mess.append("Make a sudden, destructive unpredictable action; incorporate");
  temp_mess.append("Mechanicalise something idiosyncratic");
  temp_mess.append("Mute and continue");
  temp_mess.append("Not building a wall but making a brick");
  temp_mess.append("Only one element of each kind");
  temp_mess.append("(Organic) machinery");
  temp_mess.append("Overtly resist change");
  temp_mess.append("Put in earplugs");
  temp_mess.append("Question the heroic approach");
  temp_mess.append("Remember .those quiet evenings");
  temp_mess.append("Remove ambiguities and convert to specifics");
  temp_mess.append("Remove specifics and convert to ambiguities");
  temp_mess.append("Repetition is a form of change");
  temp_mess.append("Revaluation (a warm feeling)");
  temp_mess.append("Reverse");
  temp_mess.append("Short circuit (example; a man eating peas with the idea that they will improve his virility shovels them straight into his lap)");
  temp_mess.append("Simple subtraction");
  temp_mess.append("Simply a matter of work");
  temp_mess.append("Spectrum analysis");
  temp_mess.append("State the problem in words as simply as possible");
  temp_mess.append("Take a break");
  temp_mess.append("Take away the elements in order of apparent non-importance");
  temp_mess.append("Tape your mouth (given by Ritva Saarikko)");
  temp_mess.append("The inconsistency principle");
  temp_mess.append("The most important thing is the thing most easily forgotten");
  temp_mess.append("The tape is now the music");
  temp_mess.append("Think of the radio");
  temp_mess.append("Tidy up");
  temp_mess.append("Towards the insignificant");
  temp_mess.append("Trust in the you of now");
  temp_mess.append("Turn it upside down");
  temp_mess.append("Twist the spine");
  temp_mess.append("Use an old idea");
  temp_mess.append("Use an unacceptable colour");
  temp_mess.append("Use fewer notes");
  temp_mess.append("Use filters");
  temp_mess.append("Use 'unqualified' people");
  temp_mess.append("Water");
  temp_mess.append("What are the sections sections of? Imagine a caterpillar moving");
  temp_mess.append("What are you really thinking about just now?");
  temp_mess.append("What is the reality of the situation?");
  temp_mess.append("What mistakes did you make last time?");
  temp_mess.append("What would your closest friend do?");
  temp_mess.append("What wouldn't you do?");
  temp_mess.append("What would your closest friend do?");
  temp_mess.append("Work at a different speed");
  temp_mess.append("You are an engineer");
  temp_mess.append("You can only make one dot at a time");
  temp_mess.append("You don't have to be ashamed of using your own ideas");
  temp_mess.append("");
  mess.append(temp_mess);
  temp_mess.clear();

  //  third edition
  temp_mess.append("Abandon normal instruments");
  temp_mess.append("Accept advice");
  temp_mess.append("Accretion");
  temp_mess.append("A line has two sides");
  temp_mess.append("Allow an easement (an easement is the abandonment of a stricture)");
  temp_mess.append("Always first steps");
  temp_mess.append("Are there sections? Consider transitions");
  temp_mess.append("Ask people to work against their better judgement");
  temp_mess.append("Ask your body");
  temp_mess.append("Assemble some of the elements in a group and treat the group");
  temp_mess.append("Balance the consistency principle with the inconsistency principle");
  temp_mess.append("Be dirty");
  temp_mess.append("Be extravagant");
  temp_mess.append("Be less critical more often");
  temp_mess.append("Breathe more deeply");
  temp_mess.append("Bridges -build -burn");
  temp_mess.append("Cascades");
  temp_mess.append("Change instrument roles");
  temp_mess.append("Change nothing and continue with immaculate consistency");
  temp_mess.append("Children -speaking -singing");
  temp_mess.append("Cluster analysis");
  temp_mess.append("Consider different fading systems");
  temp_mess.append("Consult other sources -promising -unpromising");
  temp_mess.append("Courage!");
  temp_mess.append("Cut a vital connection");
  temp_mess.append("Decorate, decorate");
  temp_mess.append("Define an area as 'safe' and use it as an anchor");
  temp_mess.append("Destroy -nothing -the most important thing");
  temp_mess.append("Discard an axiom");
  temp_mess.append("Disciplined self-indulgence");
  temp_mess.append("Disconnect from desire");
  temp_mess.append("Discover the recipes you are using and abandon them");
  temp_mess.append("Distorting time");
  temp_mess.append("Do nothing for as long as possible");
  temp_mess.append("Don't be afraid of things because they're easy to do");
  temp_mess.append("Don't be frightened of cliches");
  temp_mess.append("Don't be frightened to display your talents");
  temp_mess.append("Don't break the silence");
  temp_mess.append("Don't stress one thing more than another");
  temp_mess.append("Do something boring");
  temp_mess.append("Do the words need changing?");
  temp_mess.append("Do we need holes?");
  temp_mess.append("Emphasise differences");
  temp_mess.append("Emphasise repetitions");
  temp_mess.append("Emphasise the flaws");
  temp_mess.append("Fill every beat with something");
  temp_mess.append("From nothing to more than nothing");
  temp_mess.append("Ghost echoes");
  temp_mess.append("Give the game away");
  temp_mess.append("Give way to your worst impulse");
  temp_mess.append("Go outside. Shut the door.");
  temp_mess.append("Go slowly all the way round the outside");
  temp_mess.append("Go to an extreme, move back to a more comfortable place");
  temp_mess.append("Honor thy error as a hidden intention");
  temp_mess.append("How would you have done it?");
  temp_mess.append("Humanise something free of error");
  temp_mess.append("Idiot glee (?)");
  temp_mess.append("Imagine the piece as a set of disconnected events");
  temp_mess.append("Infinitesimal gradations");
  temp_mess.append("Intentions -nobility of -humility of -credibility of");
  temp_mess.append("In total darkness, or in a very large room, very quietly");
  temp_mess.append("Into the impossible");
  temp_mess.append("Is it finished?");
  temp_mess.append("Is the intonation correct?");
  temp_mess.append("Is there something missing?");
  temp_mess.append("It is quite possible (after all)");
  temp_mess.append("Just carry on");
  temp_mess.append("Listen to the quiet voice");
  temp_mess.append("Look at the order in which you do things");
  temp_mess.append("Look closely at the most embarrassing details and amplify them");
  temp_mess.append("Lost in useless territory");
  temp_mess.append("Lowest common denominator");
  temp_mess.append("Make a blank valuable by putting it in an exquisite frame");
  temp_mess.append("Make an exhaustive list of everything you might do and do the last thing on the list");
  temp_mess.append("Make a sudden, destructive unpredictable action; incorporate");
  temp_mess.append("Mechanicalise something idiosyncratic");
  temp_mess.append("Mute and continue");
  temp_mess.append("Not building a wall but making a brick");
  temp_mess.append("Once the search is in progress, something will be found");
  temp_mess.append("Only a part, not the whole");
  temp_mess.append("Only one element of each kind");
  temp_mess.append("(Organic) machinery");
  temp_mess.append("Overtly resist change");
  temp_mess.append("Question the heroic approach");
  temp_mess.append("Remember .those quiet evenings");
  temp_mess.append("Remove ambiguities and convert to specifics");
  temp_mess.append("Remove specifics and convert to ambiguities");
  temp_mess.append("Repetition is a form of change");
  temp_mess.append("Retrace your steps");
  temp_mess.append("Revaluation (a warm feeling)");
  temp_mess.append("Reverse");
  temp_mess.append("Short circuit (example; a man eating peas with the idea that they will improve his virility shovels them straight into his lap)");
  temp_mess.append("Simple subtraction");
  temp_mess.append("Simply a matter of work");
  temp_mess.append("State the problem in words as clearly as possible");
  temp_mess.append("Take a break");
  temp_mess.append("Take away the elements in order of apparent non-importance");
  temp_mess.append("The inconsistency principle");
  temp_mess.append("The most important thing is the thing most easily forgotten");
  temp_mess.append("The tape is now the music");
  temp_mess.append("Think of the radio");
  temp_mess.append("Tidy up");
  temp_mess.append("Towards the insignificant");
  temp_mess.append("Trust in the you of now");
  temp_mess.append("Turn it upside down");
  temp_mess.append("Use an old idea");
  temp_mess.append("Use an unacceptable colour");
  temp_mess.append("Use fewer notes");
  temp_mess.append("Use filters");
  temp_mess.append("Use 'unqualified' people");
  temp_mess.append("Water");
  temp_mess.append("What are the sections sections of? Imagine a caterpillar moving");
  temp_mess.append("What are you really thinking about just now?");
  temp_mess.append("What is the reality of the situation?");
  temp_mess.append("What mistakes did you make last time?");
  temp_mess.append("What wouldn't you do?");
  temp_mess.append("What would your closest friend do?");
  temp_mess.append("Work at a different speed");
  temp_mess.append("Would anybody want it?");
  temp_mess.append("You are an engineer");
  temp_mess.append("You can only make one dot at a time");
  temp_mess.append("You don't have to be ashamed of using your own ideas");
  temp_mess.append("");
  mess.append(temp_mess);
  temp_mess.clear();

  //  fouth edition
  temp_mess.append("Abandon desire");
  temp_mess.append("Abandon normal instructions");
  temp_mess.append("Accept advice");
  temp_mess.append("Adding on");
  temp_mess.append("A line has two sides");
  temp_mess.append("Always the first steps");
  temp_mess.append("Ask people to work against their better judgement");
  temp_mess.append("Ask your body");
  temp_mess.append("Be dirty");
  temp_mess.append("Be extravagant");
  temp_mess.append("Be less critical");
  temp_mess.append("Breathe more deeply");
  temp_mess.append("Bridges -build -burn");
  temp_mess.append("Change ambiguities to specifics");
  temp_mess.append("Change nothing and continue consistently");
  temp_mess.append("Change specifics to ambiguities");
  temp_mess.append("Consider transitions");
  temp_mess.append("Courage!");
  temp_mess.append("Cut a vital connection");
  temp_mess.append("Decorate, decorate");
  temp_mess.append("Destroy nothing; Destroy the most important thing");
  temp_mess.append("Discard an axiom");
  temp_mess.append("Disciplined self-indulgence");
  temp_mess.append("Discover your formulas and abandon them");
  temp_mess.append("Display your talent");
  temp_mess.append("Distort time");
  temp_mess.append("Do nothing for as long as possible");
  temp_mess.append("Don't avoid what is easy");
  temp_mess.append("Don't break the silence");
  temp_mess.append("Don't stress one thing more than another");
  temp_mess.append("Do something boring");
  temp_mess.append("Do something sudden, destructive and unpredictable");
  temp_mess.append("Do the last thing first");
  temp_mess.append("Do the words need changing?");
  temp_mess.append("Emphasize differences");
  temp_mess.append("Emphasize the flaws");
  temp_mess.append("Faced with a choice, do both (from Dieter Rot)");
  temp_mess.append("Find a safe part and use it as an anchor");
  temp_mess.append("Give the game away");
  temp_mess.append("Give way to your worst impulse");
  temp_mess.append("Go outside. Shut the door.");
  temp_mess.append("Go to an extreme, come part way back");
  temp_mess.append("How would someone else do it?");
  temp_mess.append("How would you have done it?");
  temp_mess.append("In total darkness, or in a very large room, very quietly");
  temp_mess.append("Is it finished?");
  temp_mess.append("Is something missing?");
  temp_mess.append("Is the style right?");
  temp_mess.append("It is simply a matter or work");
  temp_mess.append("Just carry on");
  temp_mess.append("Listen to the quiet voice");
  temp_mess.append("Look at the order in which you do things");
  temp_mess.append("Magnify the most difficult details");
  temp_mess.append("Make it more sensual");
  temp_mess.append("Make what's perfect more human");
  temp_mess.append("Move towards the unimportant");
  temp_mess.append("Not building a wall; making a brick");
  temp_mess.append("Once the search has begun, something will be found");
  temp_mess.append("Only a part, not the whole");
  temp_mess.append("Only one element of each kind");
  temp_mess.append("Openly resist change");
  temp_mess.append("Pae White's non-blank graphic metacard");
  temp_mess.append("Question the heroic");
  temp_mess.append("Remember quiet evenings");
  temp_mess.append("Remove a restriction");
  temp_mess.append("Repetition is a form of change");
  temp_mess.append("Retrace your steps");
  temp_mess.append("Reverse");
  temp_mess.append("Simple Subtraction");
  temp_mess.append("Slow preparation, fast execution");
  temp_mess.append("State the problem as clearly as possible");
  temp_mess.append("Take a break");
  temp_mess.append("Take away the important parts");
  temp_mess.append("The inconsistency principle");
  temp_mess.append("The most easily forgotten thing is the most important");
  temp_mess.append("Think - inside the work -outside the work");
  temp_mess.append("Tidy up");
  temp_mess.append("Try faking it (from Stewart Brand)");
  temp_mess.append("Turn it upside down");
  temp_mess.append("Use an old idea");
  temp_mess.append("Use cliches");
  temp_mess.append("Use filters");
  temp_mess.append("Use something nearby as a model");
  temp_mess.append("Use 'unqualified' people");
  temp_mess.append("Use your own ideas");
  temp_mess.append("Voice your suspicions");
  temp_mess.append("Water");
  temp_mess.append("What context would look right?");
  temp_mess.append("What is the simplest solution?");
  temp_mess.append("What mistakes did you make last time?");
  temp_mess.append("What to increase? What to reduce? What to maintain?");
  temp_mess.append("What were you really thinking about just now?");
  temp_mess.append("What wouldn't you do?");
  temp_mess.append("What would your closest friend do?");
  temp_mess.append("When is it for?");
  temp_mess.append("Where is the edge?");
  temp_mess.append("Which parts can be grouped?");
  temp_mess.append("Work at a different speed");
  temp_mess.append("Would anyone want it?");
  temp_mess.append("Your mistake was a hidden intention");
  mess.append(temp_mess);
  temp_mess.clear();

  //  copyright
  copyright.append(qApp->translate("copyright", "<p align=\"right\"><span style=\" font-size:7pt;\">1st edition (c) 1975 Brian Eno/Peter Schmidt</span></p>"));
  copyright.append(qApp->translate("copyright", "<p align=\"right\"><span style=\" font-size:7pt;\">2nd edition (c) 1978 Brian Eno/Peter Schmidt</span></p>"));
  copyright.append(qApp->translate("copyright", "<p align=\"right\"><span style=\" font-size:7pt;\">3rd edition (c) 1979 Brian Eno/Peter Schmidt</span></p>"));
  copyright.append(qApp->translate("copyright", "<p align=\"right\"><span style=\" font-size:7pt;\">4th edition (c) 1996 Brian Eno/Peter Schmidt</span></p>"));
}

void oblikuestrategies::init()
{
  setMessagesText();

  //  generate ui
  //  layout
  QGraphicsLinearLayout *layout = new QGraphicsLinearLayout(this);
  layout->setOrientation(Qt::Vertical);

  //  label
  layout->addStretch(1);
  m_label = new Plasma::Label(this);
  m_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  m_label->setToolTip(qApp->translate("tooltip", "Click here to update message"));
  layout->addItem(m_label);
  layout->addStretch(1);

  //  copyright label
  info_label = new Plasma::Label(this);
  layout->addItem(info_label);

  //  timer
  timer = new QTimer;
  timer->setSingleShot(false);

  //  read variables
  formatLine.append("");
  formatLine.append("");
  configChanged();
}

void oblikuestrategies::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  // mouse click event
  if (event->buttons() == Qt::LeftButton)
    updateEvent();
}

void oblikuestrategies::updateEvent()
{
  //  update text
  int num = rand() % mess[edition-1].count();
  m_label->setText(formatLine[0] + mess[edition-1][num] + formatLine[1]);
}

//  configuration interface
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
  if (autoUpdate_bool == false)
    uiConfig.checkBox_autoUpdate->setCheckState(Qt::Unchecked);
  else
    uiConfig.checkBox_autoUpdate->setCheckState(Qt::Checked);
  setAutoUpdate();

  parent->addPage(configwin, i18n("Oblikue Strategies"), Applet::icon());
  connect(parent, SIGNAL(okClicked()), this, SLOT(configAccepted()));
  connect(uiConfig.checkBox_autoUpdate, SIGNAL(stateChanged(int)), this, SLOT(setAutoUpdate()));
}

void oblikuestrategies::configAccepted()
{
  KConfigGroup cg = config();

  cg.writeEntry("edition", uiConfig.comboBox_edition->currentIndex()+1);
  cg.writeEntry("font_family", uiConfig.fontComboBox_font->currentFont().family());
  cg.writeEntry("font_size", uiConfig.spinBox_fontSize->value());
  cg.writeEntry("font_color", uiConfig.kcolorcombo_fontColor->color().name());
  cg.writeEntry("font_style", uiConfig.comboBox_fontStyle->currentText());
  cg.writeEntry("font_weight", uiConfig.spinBox_fontWeight->value());
  if (uiConfig.checkBox_autoUpdate->checkState() == 0)
    cg.writeEntry("auto_update_bool", false);
  else
    cg.writeEntry("auto_update_bool", true);
  cg.writeEntry("auto_update_int", uiConfig.spinBox_autoUpdate->value());
}

void oblikuestrategies::configChanged()
{
  if (autoUpdate_bool == true)
  {
    disconnect(timer, SIGNAL(timeout()), this, SLOT(updateEvent()));
    timer->stop();
  }
  KConfigGroup cg = config();

  edition = cg.readEntry("edition", 1);
  fontFamily = cg.readEntry("font_family", "Terminus");
  fontSize = cg.readEntry("font_size", 12);
  fontColor = cg.readEntry("font_color", "#000000");
  fontStyle = cg.readEntry("font_style", "normal");
  fontWeight = cg.readEntry("font_weight", 400);
  autoUpdate_bool = cg.readEntry("auto_update_bool", true);
  autoUpdate_int = cg.readEntry("auto_update_int", 60);
  formatLine[0] = ("<p align=\"justify\"><span style=\" font-family:'" + fontFamily + \
                   "'; font-style:" + fontStyle + \
                   "; font-size:" + QString::number(fontSize) + \
                   "pt; font-weight:" + QString::number(fontWeight) + \
                   "; color:" + fontColor + \
                   ";\">");
  formatLine[1] = ("</span></p>");

  //  update
  if (autoUpdate_bool == true)
  {
    connect(timer, SIGNAL(timeout()), this, SLOT(updateEvent()));
    timer->start(autoUpdate_int * MSEC_IN_MIN);
  }
  updateEvent();
  info_label->setText(copyright[edition-1]);
}

void oblikuestrategies::setAutoUpdate()
{
  if (uiConfig.checkBox_autoUpdate->checkState() == 0)
    uiConfig.spinBox_autoUpdate->setDisabled(true);
  else if (uiConfig.checkBox_autoUpdate->checkState() == 2)
    uiConfig.spinBox_autoUpdate->setEnabled(true);
}

#include "oblikue-strategies.moc"
