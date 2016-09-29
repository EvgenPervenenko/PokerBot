#include "Form.h"
#include "ui_TestForm.h"
#include "Tools/ProbabilityMath.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
	ui->setupUi(this);

    ui->Board1_comboBox->addItem( "" );
    ui->Board2_comboBox->addItem( "" );
    ui->Board3_comboBox->addItem( "" );
    ui->Board4_comboBox->addItem( "" );
	
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

void Form::on_calculateButton_clicked()
{
    auto hand1 = GetCardBySign( ui->Hand1_comboBox->currentText() );
    auto hand2 = GetCardBySign( ui->Hand2_comboBox->currentText() );

    std::vector<Entities::Card> board;

    if( ui->Board1_comboBox->currentText().isEmpty() == false )
        board.push_back( GetCardBySign( ui->Board1_comboBox->currentText() ) );

    if( ui->Board2_comboBox->currentText().isEmpty() == false )
        board.push_back( GetCardBySign( ui->Board2_comboBox->currentText() ) );

    if( ui->Board3_comboBox->currentText().isEmpty() == false )
        board.push_back( GetCardBySign( ui->Board3_comboBox->currentText() ) );

    if( ui->Board4_comboBox->currentText().isEmpty() == false )
        board.push_back( GetCardBySign( ui->Board4_comboBox->currentText() ) );


    if( qFuzzyCompare( ui->bet->value(), 0 ) == false )
    {
        auto ev = Tools::ProbabilityMath::CalculateEV( std::make_pair( hand1, hand2 ), board, ui->bank->value(), ui->bet->value() );
        ui->EV_label->setText( "EV = " + QString::number( ev ) );
    }
    else
    {
        auto coin = Tools::ProbabilityMath::CoinForMinusProbability( board, ui->bank->value() );
        ui->Coin_label->setText( "Coin = " + QString::number( coin ) );
    }


}

Entities::Card Form::GetCardBySign(const QString &sign)
{
    Entities::Rank rank = Entities::Rank::Undefind;
    Entities::Suit suit = Entities::Suit::Undefind;

    if ( sign.contains("♥") )
        suit = Entities::Suit::Heart;
    else if( sign.contains("♦") )
        suit = Entities::Suit::Heart;
    else if( sign.contains("♣") )
        suit = Entities::Suit::Heart;
    else
        suit = Entities::Suit::Heart;

    auto temp = sign;
    rank = static_cast<Entities::Rank>( temp.remove( sign.length() - 1, 1 ).toUShort() );

    return Entities::Card( rank, suit );
}
