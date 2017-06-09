class AnswersController < ApplicationController
  before_action :set_answer, only: [:show, :edit, :update, :destroy]

  # GET /answers
  # GET /answers.json
  def index
    #@answers = Answer.all
    redirect_to '/questions'
  end

  # GET /answers/1
  # GET /answers/1.json
  def show
    redirect_to '/questions'
  end

  # GET /answers/new
  def new
    @answer = Answer.new
  end

  # GET /answers/1/edit
  def edit
    redirect_to '/questions'
  end

  # POST /answers
  # POST /answers.json
  def create
    end_counter = 10    # 最大可能回答数
    @answer = Answer.new(answer_params)

    respond_to do |format|
      if @answer.save
        # 制限到達時処理
        num = Answer.where('question_id = ?', @answer.question_id).count
        if num >= end_counter
          q = Question.find(@answer.question_id)
          q.finished = true
          q.save
        end

        format.html { redirect_to '/questions/' + @answer.question_id.to_s, notice: 'Aは成功裏に創造されしまた。' }
        format.json { render :show, status: :created, location: @answer }
      else
        format.html { render :new }
        format.json { render json: @answer.errors, status: :unprocessable_entity }
      end
    end
  end

  # PATCH/PUT /answers/1
  # PATCH/PUT /answers/1.json
  def update
=begin
    respond_to do |format|
      if @answer.update(answer_params)
        format.html { redirect_to @answer, notice: 'Answer was successfully updated.' }
        format.json { render :show, status: :ok, location: @answer }
      else
        format.html { render :edit }
        format.json { render json: @answer.errors, status: :unprocessable_entity }
      end
    end
=end
    redirect_to '/questions'
  end

  # DELETE /answers/1
  # DELETE /answers/1.json
  def destroy
=begin
    @answer.destroy
    respond_to do |format|
      format.html { redirect_to answers_url, notice: 'Answer was successfully destroyed.' }
      format.json { head :no_content }
    end
=end
    redirect_to '/questions'
  end

  private
    # Use callbacks to share common setup or constraints between actions.
    def set_answer
      @answer = Answer.find(params[:id])
    end

    # Never trust parameters from the scary internet, only allow the white list through.
    def answer_params
      params.require(:answer).permit(:question_id, :content, :name)
    end
end
