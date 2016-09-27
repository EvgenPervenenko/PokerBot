#include "Form.h"
#include "ui_TestForm.h"
#include "Entities/Card.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
	ui->setupUi(this);
	
	auto limit = static_cast<unsigned short>( Entities::Rank::Ace );
	for( auto rank = static_cast<unsigned short>(Entities::Rank::Two); rank <= limit; ++rank )
	{
		QString value( QString::number( rank ) );
		
		if( rank == static_cast<unsigned short>(Entities::Rank::Jack) )
			value = "J";
		else if( rank == static_cast<unsigned short>(Entities::Rank::Queen) )
			value = "Q";
		else if( rank == static_cast<unsigned short>(Entities::Rank::King) )
			value = "K";
		else if( rank == static_cast<unsigned short>(Entities::Rank::Ace) )
			value = "A";
		
		auto dimond = value + "♦";
		auto heart = value + "♥";
		auto clubs = value + "♣";
		auto spades = value + "♠";
		
		ui->Board1_comboBox->addItem( heart );
		ui->Board1_comboBox->addItem( dimond );
		ui->Board1_comboBox->addItem( clubs );
		ui->Board1_comboBox->addItem( spades );
		
		ui->Board2_comboBox->addItem( heart );
		ui->Board2_comboBox->addItem( dimond );
		ui->Board2_comboBox->addItem( clubs );
		ui->Board2_comboBox->addItem( spades );
		
		ui->Board3_comboBox->addItem( heart );
		ui->Board3_comboBox->addItem( dimond );
		ui->Board3_comboBox->addItem( clubs );
		ui->Board3_comboBox->addItem( spades );
		
		ui->Board4_comboBox->addItem( heart );
		ui->Board4_comboBox->addItem( dimond );
		ui->Board4_comboBox->addItem( clubs );
		ui->Board4_comboBox->addItem( spades );
		
		ui->Hand1_comboBox->addItem( heart );
		ui->Hand1_comboBox->addItem( dimond );
		ui->Hand1_comboBox->addItem( clubs );
		ui->Hand1_comboBox->addItem( spades );
		
		ui->Hand2_comboBox->addItem( heart );
		ui->Hand2_comboBox->addItem( dimond );
		ui->Hand2_comboBox->addItem( clubs );
		ui->Hand2_comboBox->addItem( spades );
	}
}

Form::~Form()
{
	delete ui;
}
