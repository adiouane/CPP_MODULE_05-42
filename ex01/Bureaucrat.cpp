/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 22:38:40 by adiouane          #+#    #+#             */
/*   Updated: 2023/01/06 16:44:28 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grad_name("Default"), _grad_rang(150){};

Bureaucrat::Bureaucrat(Bureaucrat const &obj) : _grad_name(obj.getName()), _grad_rang(obj.getGrade()){}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &obj){
    _grad_rang = obj.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat(){};

/*ORTHODOX*/


Bureaucrat::Bureaucrat(std::string const &Name, int grade) : _grad_name(Name), _grad_rang(grade){
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
};

std::string Bureaucrat::getName() const{
    return _grad_name;
}

int Bureaucrat::getGrade() const{
    return _grad_rang;
}

void    Bureaucrat::increment_grade(){
    if (_grad_rang == 150)
        throw Bureaucrat::GradeTooHighException();
    _grad_rang++;
}

void    Bureaucrat::decrement_grade(){
    if (_grad_rang == 1)
        throw Bureaucrat::GradeTooHighException();
    _grad_rang--;
}

const char*Bureaucrat::GradeTooHighException::what()const throw(){
    return ("GradeTooHighException");
}

const char*Bureaucrat::GradeTooLowException::what()const throw(){
    return("GradeTooLowException");
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const &obj){
    out << obj.getName() << ", Bureaucrat grade " << obj.getGrade() << std::endl;
    return out;  
}

void  Bureaucrat::signForm(Form &form){
    try{
        form.beSigned(*this);
        std::cout << _grad_name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << _grad_name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}