object FGerenciarUsuarios: TFGerenciarUsuarios
  Left = 0
  Top = 0
  Caption = 'Gerenciar Usu'#225'rios'
  ClientHeight = 661
  ClientWidth = 884
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = 18
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 18
  object Panel1: TPanel
    Left = 0
    Top = 81
    Width = 450
    Height = 580
    Align = alLeft
    TabOrder = 0
    object StringGrid1: TStringGrid
      Left = 1
      Top = 1
      Width = 448
      Height = 578
      Align = alClient
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
      TabOrder = 0
      OnClick = StringGrid1Click
      OnDrawCell = StringGrid1DrawCell
      OnSelectCell = StringGrid1SelectCell
    end
  end
  object Panel2: TPanel
    Left = 450
    Top = 81
    Width = 434
    Height = 580
    Align = alClient
    TabOrder = 1
    ExplicitLeft = 455
    ExplicitTop = 87
    object Label1: TLabel
      Left = 20
      Top = 41
      Width = 106
      Height = 18
      Caption = 'Nome de usu'#225'rio'
    end
    object Label2: TLabel
      Left = 88
      Top = 87
      Width = 38
      Height = 18
      Caption = 'Senha'
    end
    object Label3: TLabel
      Left = 35
      Top = 133
      Width = 91
      Height = 18
      Caption = 'Repita a Senha'
    end
    object Label4: TLabel
      Left = 24
      Top = 414
      Width = 195
      Height = 18
      Caption = 'Valor m'#225'ximo de desconto (%): '
    end
    object EditUsuario: TEdit
      Left = 146
      Top = 38
      Width = 261
      Height = 26
      TabOrder = 0
    end
    object EditSenha: TEdit
      Left = 146
      Top = 84
      Width = 261
      Height = 26
      PasswordChar = '*'
      TabOrder = 1
    end
    object EditRepitirSenha: TEdit
      Left = 146
      Top = 130
      Width = 261
      Height = 26
      PasswordChar = '*'
      TabOrder = 2
    end
    object GroupBox1: TGroupBox
      Left = 18
      Top = 184
      Width = 389
      Height = 201
      Caption = 'Privil'#233'gios'
      TabOrder = 3
      object Check0: TCheckBox
        Left = 32
        Top = 32
        Width = 145
        Height = 17
        Caption = 'Abrir e Fechar Caixa'
        TabOrder = 0
      end
      object Check1: TCheckBox
        Left = 32
        Top = 72
        Width = 169
        Height = 17
        Caption = 'Emitir Relat'#243'rios F'#237'scais'
        TabOrder = 1
      end
      object Check3: TCheckBox
        Left = 32
        Top = 152
        Width = 145
        Height = 17
        Caption = 'Extornar Compra'
        TabOrder = 2
      end
      object Check2: TCheckBox
        Left = 32
        Top = 112
        Width = 145
        Height = 17
        Caption = 'Controle Financeiro'
        TabOrder = 3
      end
      object Check4: TCheckBox
        Left = 224
        Top = 32
        Width = 145
        Height = 17
        Caption = 'Gerenciar Dados'
        TabOrder = 4
      end
      object Check5: TCheckBox
        Left = 224
        Top = 72
        Width = 145
        Height = 17
        Caption = 'Gerenciar Usu'#225'rios'
        TabOrder = 5
      end
      object Check6: TCheckBox
        Left = 224
        Top = 112
        Width = 145
        Height = 17
        Caption = 'Clientes Financeiro'
        TabOrder = 6
      end
      object Check7: TCheckBox
        Left = 224
        Top = 152
        Width = 145
        Height = 17
        Caption = 'Liberar Devolu'#231#227'o'
        TabOrder = 7
      end
    end
    object Panel4: TPanel
      Left = 1
      Top = 520
      Width = 432
      Height = 59
      Align = alBottom
      TabOrder = 4
      object ButtonInserirModificar: TButton
        Left = 16
        Top = 18
        Width = 177
        Height = 25
        Caption = 'ADICIONAR'
        TabOrder = 0
        OnClick = ButtonInserirModificarClick
      end
      object ButtonDeletar: TButton
        Left = 216
        Top = 18
        Width = 177
        Height = 25
        Caption = 'DELETAR'
        TabOrder = 1
        OnClick = ButtonDeletarClick
      end
    end
    object EditDesconto: TEdit
      Left = 225
      Top = 411
      Width = 184
      Height = 26
      TabOrder = 5
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 0
    Width = 884
    Height = 81
    Align = alTop
    TabOrder = 2
    object ButtonAtualizar: TButton
      Left = 16
      Top = 29
      Width = 129
      Height = 25
      Caption = 'ATUALIZAR'
      TabOrder = 0
      OnClick = ButtonAtualizarClick
    end
    object ButtonNovoUsuario: TButton
      Left = 168
      Top = 29
      Width = 185
      Height = 25
      Caption = 'NOVO USU'#193'RIO'
      TabOrder = 1
      OnClick = ButtonNovoUsuarioClick
    end
  end
  object SQLQuery1: TSQLQuery
    Params = <>
    Left = 216
    Top = 136
  end
end
